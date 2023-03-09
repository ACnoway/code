#include <bits/stdc++.h>
#include <bits/extc++.h>
#define INF 0x7fffffff
#define MAXN 200005
#define eps 1e-9
#define foru(a, b, c) for (int a = b; a <= c; a++)
#define RT return 0;
#define LL long long
#define LXF int
#define RIN rin()
#define HH printf("\n")
using namespace std;
inline LXF rin()
{
    LXF x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int n, m;
class Edge
{
public:
    int v, w;
};
class E
{
public:
    int u, v, h;
};
class Point
{
public:
    int u, dis;
    bool operator<(const Point _x) const
    {
        return this->dis > _x.dis;
    }
};
priority_queue<Point> q;
vector<vector<Edge>> e;     // 原图
vector<vector<int>> g;      // 重构树
vector<pair<int, int>> val; // 点权
vector<int> jh;             // 并查集
vector<E> edge;             // 存边
vector<array<int, 24>> fa;
vector<array<int, 24>> Min;
vector<int> dep;
int find(int x)
{
    return jh[x] == x ? x : jh[x] = find(jh[x]);
}
bool cmp(E p, E q)
{
    return p.h > q.h;
}
void dijkstra(int s)
{
    foru(i, 1, n) val[i].second = INT_MAX;
    val[s].second = 0;
    priority_queue<Point>().swap(q);
    q.push({s, val[s].second});
    while (!q.empty())
    {
        auto now = q.top();
        q.pop();
        int u = now.u, ds = now.dis;
        if (val[u].second != ds)
            continue;
        for (auto [v, w] : e[u])
        {
            if (val[v].second > val[u].second + w)
            {
                val[v].second = val[u].second + w;
                q.push({v, val[v].second});
            }
        }
    }
}
void dfs(int u, int fath)
{
    fa[u][0] = fath;
    Min[u][0] = min(val[u].first, val[fath].first);
    dep[u] = dep[fath] + 1;
    for (int i = 1; i <= __lg(dep[u]); i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        Min[u][i] = min(Min[u][i - 1], Min[fa[u][i - 1]][i - 1]);
    }
    for (auto v : g[u])
    {
        if (v == fath)
            continue;
        dfs(v, u);
    }
}
signed main()
{
    auto T = RIN;
    while (T--)
    {
        n = RIN, m = RIN;

        // 清空
        e.clear();
        g.clear();
        jh.clear();
        val.clear();
        edge.clear();
        val.resize(n + 1);
        jh.resize(n + 1);
        e.resize(n + 1);
        g.resize(n + 1);

        // 读边
        foru(i, 1, m)
        {
            auto u = RIN, v = RIN, w = RIN, h = RIN;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
            edge.push_back({u, v, h});
        }

        dijkstra(1);

        // MST预处理
        foru(i, 1, n) jh[i] = i, val[i].first = INT_MAX;
        sort(edge.begin(), edge.end(), cmp);

        // MST
        for (auto [u, v, h] : edge)
        {
            auto fu = find(u), fv = find(v);
            if (fu != fv)
            {
                auto node = g.size();
                g.resize(node + 1);
                val.resize(node + 1);
                jh.resize(node + 1);

                val[node] = make_pair(h, min(val[fu].second, val[fv].second));

                g[node].push_back(fu);
                g[node].push_back(fv);
                g[fu].push_back(node);
                g[fv].push_back(node);

                jh[fu] = jh[fv] = jh[node] = node;
            }
        }

        fa.clear();
        Min.clear();
        dep.clear();
        fa.resize(g.size());
        Min.resize(g.size());
        dep.resize(g.size());

        dfs(find(1), 0);

        auto Q = RIN, K = RIN, S = RIN, la = 0;

        while (Q--)
        {
            auto s = RIN, p = RIN;
            s = (s + K * la - 1) % n + 1;
            p = (p + K * la) % (S + 1);

            for (int i = 22; i >= 0; i--)
            {
                if (Min[s][i] > p)
                {
                    s = fa[s][i];
                }
            }
            printf("%d\n", la = val[s].second);
        }
    }
    return 0;
}
