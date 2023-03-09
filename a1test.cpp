#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5, maxm = 5e4 + 5;
struct edge
{
    int u, v, w;
} e[maxm];
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
struct node
{
    int to, weight;
};
vector<node> edg[maxn];
int n, m, f[maxn], x, y, fa[maxn][20], dep[maxn], q, minn[maxn][20]; // 统计每个点向上跳
bool cmp(edge a, edge b) { return a.w > b.w; }
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        f[i] = i;
}
int findf(int i) { return f[i] == i ? f[i] : f[i] = findf(f[i]); }
void merge(int i, int j) { f[findf(i)] = findf(j); }
void dfs(int u, int fath, int weight)
{
    fa[u][0] = fath;
    dep[u] = dep[fath] + 1;
    minn[u][0] = weight;
    for (int i = 1; (1 << i) <= dep[u]; ++i)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        minn[u][i] = min(minn[u][i - 1], minn[fa[u][i - 1]][i - 1]);
    }
    for (auto v : edg[u])
    {
        if (v.to == fath)
            continue;
        dfs(v.to, u, v.weight);
    }
}
int lca(int u, int v)
{
    int mmin = 0x7fffffff;
    if (dep[u] < dep[v])
        swap(u, v);
    while (dep[u] > dep[v])
    {
        mmin = min(mmin, minn[u][(int)__lg(dep[u] - dep[v])]);
        u = fa[u][(int)__lg(dep[u] - dep[v])];
    }
    if (v == u)
        return mmin;
    for (int i = __lg(dep[u]); i >= 0; --i)
    {
        if (fa[u][i] != fa[v][i])
        {
            mmin = min(mmin, minn[u][i]);
            mmin = min(mmin, minn[v][i]);
            u = fa[u][i], v = fa[v][i];
        }
    }
    mmin = min(mmin, minn[u][0]);
    mmin = min(mmin, minn[v][0]);
    return mmin;
}
int cnt;
bool vis[maxn];
signed main()
{
    n = read(), m = read();
    init(n);
    for (int i = 1; i <= m; ++i)
        e[i].u = read(), e[i].v = read(), e[i].w = read();
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; ++i)
    {
        if (findf(e[i].u) == findf(e[i].v))
            continue;
        cnt++;
        edg[e[i].u].push_back((node){e[i].v, e[i].w});
        edg[e[i].v].push_back((node){e[i].u, e[i].w});
        merge(e[i].v, e[i].u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[findf(i)])
        {
            dfs(findf(i), 0, 0);
            vis[findf(i)] = 1;
        }
    }
    q = read();
    for (int i = 1; i <= q; ++i)
    {
        x = read(), y = read();
        if (findf(x) != findf(y))
            printf("-1\n");
        else
            printf("%d\n", lca(x, y));
    }
    return 0;
}