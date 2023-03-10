#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout << ' ' << #x << '=' << x << endl
#endif
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
const int N = 1000005, M = 2000005;
int n, m, k, l;
int a[N], b[N], ans[N], dis[N];
bool teshu[N], vis[N];
struct Node
{
    int to, w;
};
vector<Node> e[N];

//* -----迪杰斯特拉
struct dnode
{
    int pos, dis;
    bool operator<(const dnode o) const
    {
        return dis > o.dis;
    }
};
priority_queue<dnode> q;
void dijkstra()
{
    priority_queue<dnode>().swap(q);
    for (int i = 0; i <= n; ++i)
        dis[i] = LONG_LONG_MAX>>1, vis[i] = 0;
    dis[0] = 0;
    q.push({0, 0});
    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();
        int x = tmp.pos;
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto now : e[x])
        {
            int y = now.to;
            if (dis[y] > dis[x] + now.w)
            {
                dis[y] = dis[x] + now.w;
                q.push({y, dis[y]});
            }
        }
    }
}

signed main()
{
    n = read();
    m = read();
    k = read();
    l = read();
    for (int i = 0; i <= n; ++i)
        ans[i] = LONG_LONG_MAX>>1;
    for (int i = 1; i <= n; ++i)
        a[i] = read(); // 表示这个点的颜色
    for (int i = 1; i <= l; ++i)
    {
        b[i] = read();
        teshu[b[i]] = 1;
    }
    for (int i = 1; i <= m; ++i)
    {
        int x = read(), y = read(), c = read();
        if (x == y)
            continue;
        e[x].push_back({y, c});
        e[y].push_back({x, c});
    }
    // 处理二进制
    bool opt;
    opt = 1;
    while (opt)
    {
        opt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((a[i] & 1) && teshu[i])
                e[0].push_back({i, 0});
        }
        dijkstra();
        for (int i = 1; i <= n; ++i)
        {
            if ((!(a[i] & 1)))
                ans[i] = min(ans[i], dis[i]);
        }
        e[0].clear();
        for (int i = 1; i <= n; ++i)
        {
            if ((!(a[i] & 1)) && teshu[i])
                e[0].push_back({i, 0});
        }
        dijkstra();
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] & 1)
                ans[i] = min(ans[i], dis[i]);
        }
        e[0].clear();
        for (int i = 1; i <= n; ++i)
        {
            a[i] >>= 1;
            if (a[i])
                opt = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] == LONG_LONG_MAX>>1)
            printf("-1 ");
        else
            printf("%lld ", ans[i]);
    }
    return 0;
}