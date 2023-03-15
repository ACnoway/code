#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define debug(x) cout<<#x<<" = "<<x<<endl
#define INF 0x3f3f3f3f
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (; isdigit(ch); ch = getchar())
        x = (x << 3) + (x << 1) + ch - '0';
    return x * f;
}

const int N = 5000050;
const int M = 5050;

int n, m, a[N], Vis[N], tot, dfn[N], low[N], stk[N], sc, Belong[N], Sum[N], t, cnt;
int pre[N], Size[N], depth[N], fa[N], son[N], Tot, head[N], Head[N], top[N];
bool vis[N];
int Cnt, Q;
struct node
{
    int u, v, nxt;
} edge[N], E[N];
void Add_edge(int u, int v)
{
    edge[++cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
}
void Add(int u, int v)
{
    E[++Cnt].v = v;
    E[Cnt].u = u;
    E[Cnt].nxt = Head[u];
    Head[u] = Cnt;
}

int dep[N], f[N][21];

int LCA(int x, int y)
{
    if (dep[x] > dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[x] + (1 << i) <= dep[y])
            y = f[y][i];
    if (x == y)
        return x;
    for (int i = 20; i >= 0; i--)
    {
        if (f[x][i] == f[y][i])
            continue;
        else
        {
            y = f[y][i];
            x = f[x][i];
        }
    }
    return f[x][0];
}
void tarjan(int now, int fath)
{
    low[now] = dfn[now] = ++tot;
    stk[++sc] = now;
    vis[now] = 1;
    for (int i = head[now]; i; i = edge[i].nxt)
    {
        int to = edge[i].v;
        if (!dfn[to])
            tarjan(to, now), low[now] = min(low[now], low[to]);
        else if (vis[to] && to != fath)
            low[now] = min(low[now], dfn[to]);
    }
    if (dfn[now] == low[now])
    {
        int pre = stk[sc--];
        Sum[++t] += a[pre];
        Belong[pre] = t;
        vis[pre] = 0;
        debug(t);
        while (pre != now)
        {
            pre = stk[sc--], Sum[t] += a[pre];
            Belong[pre] = t;
            vis[pre] = 0;
        }
    }
}
long long Ans;
void Dfs(int now, int fath)
{
    for (int i = Head[now]; i; i = E[i].nxt)
    {
        if (E[i].v != fath)
            Dfs(E[i].v, now),
                Vis[now] += Vis[E[i].v];
    }
    if (Vis[now])
        Ans += Sum[now];
}

signed main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, u, v; i <= m; i++)
    {
        u = read();
        v = read();
        Add_edge(u, v);
        Add_edge(v, u);
    }
    Q = read();
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, 0);
    for (int i = 1; i <= cnt; i += 2)
    {
        if (Belong[edge[i].u] ^ Belong[edge[i].v])
        {
            Add(Belong[edge[i].u], Belong[edge[i].v]);
            Add(Belong[edge[i].v], Belong[edge[i].u]);
        }
    }
    memset(dfn, 0, sizeof dfn);
    for (int i = 1; i <= Q; i++)
    {
        int u = read(), v = read();
        int Lca = LCA(Belong[u], Belong[v]);
        Vis[Belong[u]]++;
        Vis[Belong[v]]++;
        Vis[Lca]--;
        debug(Lca);
        Vis[fa[Lca]]--;
        debug(fa[Lca]);
        Vis[f[Lca][0]]--;
        debug(f[Lca][0]);
    }
    Dfs(Belong[1], 0);
    printf("%lld\n", Ans);
    return 0;
}
