#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int M = 1100000;
inline int read()
{
    int x = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - '0';
    return x;
}
int n, m, tim, top, pat;
int part, ans, res;
int has[M], d[M], f[M];
// has--该连通快中的节点数  ；d--该连通快的入度
// f--该连通快到达起点（教学楼）的道路数量；
int dfn[M], low[M], blg[M]; // tarjan重要用的东西
int last[M], head[M];       // last在二次构图的时候用
bool is[M];                 // 记录该连通块是否是有环的联通块
stack<int> stk;
struct edge
{
    int v, next;
} e[M], g[M];

void add(int u, int v)
{
    e[pat].next = head[u];
    e[pat].v = v;
    head[u] = pat++;
} // 一次构图的时候用
void add2(int u, int v)
{
    g[pat].next = last[u];
    g[pat].v = v;
    last[u] = pat++;
} // 二次构图的时候用
void tarjan(int u)
{
    bool flag = false; // 记录是否有自环
    dfn[u] = low[u] = ++tim;
    stk.push(u);
    for (int i = head[u]; i != -1; i = e[i].next)
    {
        int v = e[i].v;
        if (u == v)
            flag = true; // 自环的判断
        if (!dfn[v])
            tarjan(v), low[u] = min(low[u], low[v]);
        else if (!blg[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int j = 0;
        ++part;
        if (flag || stk.top() != u)
            is[part] = true; // 判断是否有环（或者自环），有的话那么出发点到该联通块后就有无数条路好走了
        do
        {
            j = stk.top();
            stk.pop();
            blg[j] = part;
            ++has[part];
        } while (j != u);
    }
}

void topo()
{
    queue<int> Q;
    f[blg[n]] = 1;
    for (int i = 1; i <= part; ++i)
        if (!d[i])
            Q.push(i);
    while (!Q.empty()) // 把那些没有入度的点（除了出发点）弹出，事实上不弹也没事儿！
    {
        int now = Q.front();
        Q.pop();
        if (now == blg[n])
            continue;
        for (int i = last[now]; i != -1; i = g[i].next)
        {
            --d[g[i].v];
            if (!d[g[i].v])
                Q.push(g[i].v);
        }
    }
    Q.push(blg[n]); // 无论如何要把起点塞回去

    while (!Q.empty()) // 然后一直拓扑就ok了
    {
        int now = Q.front();
        Q.pop();
        if (is[now] && f[now])
            f[now] = 36501; // 有环就给最大值
        for (int i = last[now]; i != -1; i = g[i].next)
        {
            f[g[i].v] = min(f[g[i].v] + f[now], 36501); // 最大为36501
            --d[g[i].v];
            if (!d[g[i].v])
                Q.push(g[i].v);
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(last, -1, sizeof(last));
    n = read();
    m = read();
    ++n;
    for (int i = 0; i < m; ++i) // 反着加边，等下 操作会方便很多
    {
        int u = read(), v = read();
        add(v, u);
    }
    pat = 0;

    for (int i = 1; i <= n; ++i) // tarjan缩点
        if (!dfn[i])
            tarjan(i);

    for (int i = 1; i <= n; ++i) // 重构图
        for (int j = head[i]; j != -1; j = e[j].next)
            if (blg[i] != blg[e[j].v])
                add2(blg[i], blg[e[j].v]), ++d[blg[e[j].v]];
    topo();
    for (int i = 1; i <= part; ++i)
        ans = max(ans, f[i]);
    // 拓扑一下后找到起点道路数最大的点
    if (ans == 36501)
        printf("zawsze\n");
    else
        printf("%d\n", ans); // 这都是按题目讲的来做了
    if (ans == f[blg[n]])
        --res; // 挪，这里就是区别，等会儿讲
    for (int i = 1; i <= part; ++i)
        if (ans == f[i])
            res += has[i];
    printf("%d\n", res);
    for (int i = 1; i < n; ++i) // 这里也是区别滴~~~
        if (ans == f[blg[i]])
            printf("%d ", i);
    printf("\n");
    return 0;
}
