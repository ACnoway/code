#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, M = 1e4 + 5;
int n, m, vis[M << 1], du[N], ans;
int cnt = 1, head[N], u[M], v[M];
int now, top, col, dfn[N], low[N], sta[N], color[N];
struct edge
{
    int next, to;
} e[M << 1];

inline void add(int u, int v)
{
    cnt++;
    e[cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
    cnt++;
    e[cnt].next = head[v];
    e[cnt].to = u;
    head[v] = cnt;
}

inline void tarjan(int u)
{
    dfn[u] = low[u] = ++now;
    sta[++top] = u;
    for (register int i = head[u]; i; i = e[i].next)
        if (!vis[i])
        {
            vis[i] = vis[i ^ 1] = 1;
            if (!dfn[e[i].to])
            {
                tarjan(e[i].to);
                low[u] = min(low[u], low[e[i].to]);
            }
            else
                low[u] = min(low[u], dfn[e[i].to]);
        }
    if (low[u] == dfn[u])
    {
        color[u] = ++col;
        while (sta[top] != u)
            color[sta[top]] = col, top--;
        top--;
    }
}

int main()
{
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(head));
    // 下面过程如果不懂，看前面的几篇题解吧
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= m; ++i)
        scanf("%d%d", &u[i], &v[i]), add(u[i], v[i]);
    for (register int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);
    for (register int i = 1; i <= m; ++i)
        if (color[u[i]] != color[v[i]])
            du[color[u[i]]]++, du[color[v[i]]]++;
    for (register int i = 1; i <= col; ++i)
        if (du[i] == 1)
            ans++;
    printf("%d\n", ans + 1 >> 1);
    return 0;
}
