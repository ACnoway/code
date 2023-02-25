#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
const int maxn = 5e3 + 5, maxm = 1e6 + 5;
int a[maxn], n;
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
int ans, vis[maxm * 2], cnt[maxm]; // 统计任意两点之间的异或和
signed main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read(), cnt[a[i]]++;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            vis[a[i] ^ a[j]]++;
    // 就是记录一下有多少点对 是在这个区间范围内
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i] == a[j])
            {
                ans -= (cnt[a[i]] - 2), ans -= (cnt[a[j]] - 2);
                ans -= 1;
                ans += vis[a[i] ^ a[j]];
            }
            else
            {
                ans -= (cnt[a[i]] - 1), ans -= (cnt[a[j]] - 1);
                ans -= 1;
                ans += vis[a[i] ^ a[j]];
            }
        }
    }
    ans /= 6;
    printf("%lld", ans);
    return 0;
}