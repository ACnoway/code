#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, mod = 998244353, inv2 = (mod + 1) / 2;

int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -w;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = (s << 1) + (s << 3) + (ch ^ '0');
        ch = getchar();
    }
    return s * w;
}
int n, ans, a[N], fa[N], suba[N], du[N], dv[N], f[N], g[N];
vector<int> GA[N];
inline void chksum(int x, int &y)
{
    y += x;
    if (y >= mod)
        y -= mod;
}
inline int Div(int x) { return x %= mod, (x & 1) ? ((x * inv2) % mod) : (x >> 1); }
void dfs(int u, int F)
{
    suba[u] = a[u], fa[u] = F;
    for (int v : GA[u])
    {
        if (v ^ F)
            dfs(v, u), chksum(suba[v], suba[u]);
    }
}
signed main()
{
    freopen("aw.in", "r", stdin);
    freopen("aw.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
        f[i] = a[i] = read(), g[i] = (a[i] * a[i]) % mod;
    for (int i = 1; i < n; i++)
        du[i] = read(), GA[du[i]].emplace_back(dv[i] = read());
    dfs(1, 0);
    for (int i = 1; i < n; i++)
    {
        int x = du[i], y = dv[i];
        if (fa[x] == y)
            swap(x, y);

        int t = suba[y], s = (suba[1] - t + mod) % mod;
        int fx = f[x], fy = f[y], gx = g[x], gy = g[y];
        chksum(Div(s * t + (s + mod - t) * fx + mod - gx), ans);
        chksum(Div(s * t + (t + mod - s) * fy + mod - gy), ans);
        f[x] = f[y] = Div(fx + fy), g[x] = g[y] = Div(gx + gy + 2 * fx * fy);
    }
    for (int i = 1; i < n; i++)
        (ans <<= 1) %= mod;
    return cout << (ans % mod + mod) % mod, 0;
}