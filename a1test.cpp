#include <bits/stdc++.h>
#define int long long
#define db double

long long read()
{

    long long _ = 0, __ = 1;
    char ___ = getchar();
    while (___ > '9' || ___ < '0')
    {
        if (___ == '-')
            __ = -1;
        ___ = getchar();
    }
    while (___ >= '0' && ___ <= '9')
    {
        _ = _ * 10 + ___ - '0';
        ___ = getchar();
    }
    return __ == 1 ? _ : -_;
}

const long long INF = 1e18, inf = 1e9, Uinf = 1ll << 31;
const double eps = 1e-12, pi_ = acos(-1.0);
const double inf_double = 1e9, INF_double = 1e18;
const long long bighsh = 999983;

long long gcd(long long __, long long ___)
{
    if (!__)
        return ___;
    return ___ == 0 ? __ : gcd(___, __ % ___);
}
long long lcm(long long __, long long ___)
{
    return __ / gcd(__, ___) * ___;
}
double disttt_xy(double x_1, double y_1, double x_2, double y_2)
{
    return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}
bool cmp_ge(long long a, long long b)
{
    return a > b;
}
bool eq0(double fixdf)
{
    return fabs(fixdf) < eps;
}
bool eq(double dbnum1, double dbnum2)
{
    return fabs(dbnum1 - dbnum2) < eps;
}

#define Strelitzia_ 0

const int N = 5e5 + 3;

int f[N], val[N], n, m, anshop;
bool valed[N];
char ch[N];

int find(int x)
{
    if (x != f[x])
    {
        int fx = f[x];
        f[x] = find(f[x]), val[x] += val[fx];
    }
    return f[x];
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i] = i;

    while (m--)
    {

        int a = read(), b = read(), c = read(), fa = find(a), fb = find(b);

        if (fa == fb)
        {
            if (val[a] - val[b] != c)
                ch[++anshop] = 'W';
            else
                ch[++anshop] = 'R';
            continue;
        }

        f[fa] = fb, val[fa] = -val[a] + val[b] + c, ch[++anshop] = 'R';
    }

    for (int i = 1; i <= anshop; i++)
        putchar(ch[i]);
}