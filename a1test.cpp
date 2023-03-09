#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 4e5 + 5;
struct ed
{
    int from, to, cd, hb; // 长度与海拔
} e[maxn];
struct node
{
    int to, weight;
};
int T, n, m, dis[maxn], dep[maxn], fa[maxn][20], f[maxn], lastans, s[maxn], Query, K, S; // s记录重构树的点权
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        f[i] = i;
}
int findf(int i) { return f[i] == i ? f[i] : f[i] = findf(f[i]); }
bool vis[maxn];
vector<node> edge[maxn];
bool cmp(ed a, ed b) { return a.hb > b.hb; }
struct dui
{
    int id, dis;
    bool operator<(const dui x) const
    {
        return dis > x.dis; // 从小到大去更新答案
    }
};
priority_queue<dui> Q;
void dijkstra()
{
    while (!Q.empty())
    {
        dui x = Q.top();
        Q.pop();
        if (vis[x.id])
            continue;
        vis[x.id] = 1;
        int u = x.id;
        for (auto [v, w] : edge[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                Q.push((dui){v, dis[v]});
            }
        }
    }
}
vector<int> cgedge[maxn]; // 重构树
void dfs(int u, int fath)
{
    dep[u] = dep[fath] + 1;
    fa[u][0] = fath;
    for (int i = 1; (1 << i) <= dep[u]; ++i)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto v : cgedge[u])
    {
        if (v == fath)
            continue;
        dfs(v, u);
        dis[u] = min(dis[u], dis[v]);
    }
}
int query(int u, int p)
{
    for (int i = (int)__lg(dep[u]); i >= 0; --i)
    {
        if (s[fa[u][i]] > p)
            u = fa[u][i];
    }
    return dis[u];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        lastans = 0;
        memset(dep, 0, sizeof dep);
        memset(fa, 0, sizeof fa);
        for (int i = 1; i <= n; ++i)
            edge[i].clear();
        for (int i = 1; i <= 2 * n; ++i)
            cgedge[i].clear();
        for (int i = 1; i <= m; ++i)
        {
            int u, v, l, a;
            cin >> u >> v >> l >> a;
            e[i] = (ed){u, v, l, a}; // 存到边数组内
            edge[u].push_back((node){v, l});
            edge[v].push_back((node){u, l});
        }
        while (!Q.empty())
            Q.pop();
        memset(vis, 0, sizeof vis);
        memset(dis, 0x3f, sizeof dis);
        dis[1] = 0;
        Q.push((dui){1, dis[1]});
        dijkstra();
        sort(e + 1, e + m + 1, cmp); // 按照海拔从大到小加入答案
        int nod = n;
        init(2 * n);
        for (int i = 1; i <= n; ++i)
            s[i] = INF;
        s[0] = -INF;
        for (int i = 1; i <= m; ++i)
        {
            int u = findf(e[i].from), v = findf(e[i].to);
            if (u == v)
                continue;
            nod++;
            s[nod] = e[i].hb;
            f[u] = f[v] = f[nod] = nod;
            cgedge[u].push_back(nod);
            cgedge[v].push_back(nod); // 建好重构树
            cgedge[nod].push_back(u);
            cgedge[nod].push_back(v);
        }
        dfs(nod, 0);
        cin >> Query >> K >> S;
        while (Query--)
        {
            int u0, p0;
            cin >> u0 >> p0;
            u0 = (u0 + K * lastans - 1) % n + 1;
            p0 = (p0 + K * lastans) % (S + 1);
            lastans = query(u0, p0);
            printf("%lld\n", lastans);
        }
    }
    return 0;
}