// 请使用C++11编译
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1000001;
struct edge
{
    int to, next;
};
int head[N];
vector<edge> E;
void insert(int u, int v)
{
    E.push_back({v, head[u]});
    head[u] = E.size() - 1;
}
int dfn[N], finish[N], low[N], now;
int d[N], fa[N][20], lg[N];
void tarjan(int u, int f)
{
    d[u] = d[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= lg[d[u]]; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    dfn[u] = low[u] = ++now;
    for (int i = head[u]; ~i; i = E[i].next)
    {
        int v = E[i].to;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (v != f)
            low[u] = min(low[u], dfn[v]);
    }
    finish[u] = ++now;
}
int lca(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);
    while (d[x] > d[y])
        x = fa[x][lg[d[x] - d[y]] - 1];
    if (x == y)
        return x;
    for (int i = lg[d[x]] - 1; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}
int n, m, q;

// 判断节点 f 是否包含节点 a
bool contains(int f, int a)
{
    return dfn[f] <= dfn[a] && finish[f] >= finish[a];
}

// 查找 f 到 a （ f 包含 a ）的路径上，与 f 直接相连的点
int find_related_child(int f, int a)
{
    int df = d[f] + 1;
    while (d[a] > df)
        a = fa[a][lg[d[a] - df] - 1];
    return a;
}
bool query1(int a, int b, int g1, int g2)
{
    if (a == b)
        return true;
    if (dfn[a] > dfn[b])
        swap(a, b);
    if (dfn[g1] > dfn[g2])
        swap(g1, g2);
    if (d[g2] != d[g1] + 1)
        return true;    // g1 -> g2 为回边
    if (contains(a, b)) // a 包含 b
    {
        if (contains(a, g1) && contains(g2, b))
        {
            return low[g2] <= dfn[g1];
        }
        else
            return true;
    }
    else
    {
        int l = lca(a, b);
        return query1(a, l, g1, g2) && query1(b, l, g1, g2);
    }
}
bool query2(int a, int b, int c)
{
    if (a == b)
        return a != c;
    if (a == c || b == c)
        return false;
    if (dfn[a] > dfn[b])
        swap(a, b);
    if (contains(a, b)) // a 包含 b
    {
        if (contains(a, c) && contains(c, b))
        {
            return low[find_related_child(c, b)] < dfn[c]; // 注意这里是小于
        }
        else
            return true;
    }
    else
    {
        int l = lca(a, b);
        if (contains(l, c) && (contains(c, a) || contains(c, b)))
        {
            return query2(a, fa[l][0], c) && query2(b, fa[l][0], c);
        }
        else
            return true;
    }
}
int main()
{
    memset(head, -1, sizeof head);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    tarjan(1, 1);
    cin >> q;
    for (int i = 1, a, b, c, d; i <= q; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> a >> b >> c >> d;
            cout << (query1(a, b, c, d) ? "yes" : "no") << endl;
        }
        else
        {
            cin >> a >> b >> c;
            cout << (query2(a, b, c) ? "yes" : "no") << endl;
        }
    }
    return 0;
}
