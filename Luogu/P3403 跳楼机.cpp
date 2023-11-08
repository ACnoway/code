#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
int read()
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
const int N = 1000005, M = 4000005, inf = (1ull << 63) - 1;
int h, x, y, z;
int idx, head[N], to[M], nxt[M], w[M];
inline void add(int u, int v, int _w)
{
    to[++idx] = v;
    nxt[idx] = head[u];
    w[idx] = _w;
    head[u] = idx;
}
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;
int dis[N];
bool vis[N];
inline void dij(int st)
{
    for (int i = 0; i < N; ++i)
        dis[i] = inf, vis[i] = 0;
    q.emplace((pii){1, st});
    dis[st] = 1;
    int u, v;
    while (q.size())
    {
        u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i])
        {
            v = to[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                q.emplace((pii){dis[v], v});
            }
        }
    }
}
signed main()
{
    h = read();
    x = read(), y = read(), z = read();
    if(x==1||y==1||z==1){
        printf("%lld\n",h);
        return 0;
    }
    for (int i = 0; i < x; ++i)
    {
        add(i, (i + y) % x, y);
        add(i, (i + z) % x, z);
    }
    dij(1);
    int ans = 0;
    for (int i = 0; i < x; ++i)
    {
        if (h >= dis[i])
            ans += (h - dis[i]) / x + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
