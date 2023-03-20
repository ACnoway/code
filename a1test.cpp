#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define int long long
#define fi first
#define se second
inline int read()
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
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
const int mod = 1000000007;
inline int fpow(int n, int p)
{
    n %= mod;
    int ans = 1, base = n;
    while (p)
    {
        if (p & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ans;
}
int n, vis[200010], cj = 1, ans = 1;
vector<pair<int, int>> mp;
bool flag = 1;
signed main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        vis[read()]++;
    for (int i = 1; i <= 200000; ++i)
        cj = cj * (vis[i] + 1) % (mod - 1);
    for (int i = 1; i <= 200000; ++i)
        if (vis[i])
            mp.push_back(make_pair(vis[i], i));
    for (int i = 0; i < mp.size(); ++i)
    {
        if (mp[i].fi & 1)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    { // 情况 2
        for (int i = 0; i < mp.size(); ++i)
            mp[i].fi >>= 1;
        for (int i = 0; i < mp.size(); ++i)
            ans = ans * fpow(mp[i].se, cj * mp[i].fi % (mod - 1)) % mod;
    }
    else
    { // 情况 1
        cj = 1;
        bool FI = 1;
        for (int i = 0; i < mp.size(); ++i)
        {
            if (mp[i].fi & 1 && FI)
            {
                FI = 0;
                cj = cj * (mp[i].fi + 1) / 2 % (mod - 1);
            }
            else
                cj = cj * (mp[i].fi + 1) % (mod - 1);
        }
        for (int i = 0; i < mp.size(); ++i)
            ans = ans * fpow(mp[i].se, cj * mp[i].fi % (mod - 1)) % mod;
    }
    printf("%lld", ans);
    return 0;
}
