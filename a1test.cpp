// LUOGU_RID: 97414502
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 5e5 + 7;
int p[N + N], zc;
ll z[N];
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
        return x = 1, y = 0, a;
    int t = exgcd(b, a % b, y, x);
    return y -= (a / b) * x, t;
}
int main()
{
    int n, m, g, x, y, t;
    ll k, ls;
    scanf("%d%d%lld", &n, &m, &k);
    g = exgcd(n, m, x, y);
    ls = (ll)n * m / g;
    x = (x + m) % m;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &t), p[t] = i;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &t);
        if (p[t] && !((i - p[t]) % g))
            z[++zc] = (((ll)x * ((i - p[t]) / g) * n + p[t] - 1) % ls + ls) % ls + 1;
    }
    ll F = ls - zc, f = (k - 1) / F, mf = (k - 1) % F + 1;
    int pos = zc + 1;
    std::sort(z + 1, z + zc + 1);
    for (int i = 1; i <= zc; ++i)
        if (mf <= z[i] - i)
        {
            pos = i;
            break;
        }
    printf("%lld", f * ls + mf + pos - 1);
    return 0;
}