#include <iostream>
#include <algorithm>
#define mod 1000000007
#define int long long
using namespace std;
int kd()
{
    int x = 0, f = 1;
    char a = getchar();
    while (a < '0' || a > '9')
    {
        if (a == '-')
        {
            f = -1;
        }
        a = getchar();
    }
    while (a >= '0' && a <= '9')
    {
        x = x * 10 + a - '0';
        a = getchar();
    }
    return x * f;
}
int n, g, l;
int q;
int dui[100010], cnt;
int ans[100010];
bool cmp(int x, int y)
{
    return x < y;
}
int gd[2010][2010];
int lm[2010][2010];
int f[2010][2010];
int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}
int er;
int ksm(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y % 2 == 1)
        {
            ans = 1ll * ans * x % mod;
        }
        x = 1ll * x * x % mod;
        y /= 2;
    }
    return ans;
}
signed main()
{
    er = ksm(2, mod - 2);
    cin >> n >> g >> l;
    if (l % g != 0)
    {
        cin >> q;
        while (q--)
        {
            int x;
            x = kd();
            cout << 0 << endl;
        }
        return 0;
    }
    for (int i = 1; i * i <= l; i++)
    {
        if (l % i == 0)
        {
            if (i % g == 0)
            {
                dui[++cnt] = i;
            }
            if (i * i < l)
            {
                if ((l / i) % g == 0)
                {
                    dui[++cnt] = l / i;
                }
            }
        }
    }
    sort(dui + 1, dui + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = i; j <= cnt; j++)
        {
            gd[i][j] = gcd(dui[i], dui[j]);
            lm[i][j] = dui[i] * dui[j] / gd[i][j];
            int l = 1, r = cnt;
            if (gd[i][j] < dui[l] || gd[i][j] > dui[r])
            {
                gd[i][j] = 0;
            }
            else
            {
                while (l < r)
                {
                    int mid = (l + r) / 2;
                    if (dui[mid] >= gd[i][j])
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                if (dui[l] == gd[i][j])
                {
                    gd[i][j] = l;
                }
                else
                {
                    gd[i][j] = 0;
                }
            }
            l = 1, r = cnt;
            if (lm[i][j] < dui[l] || lm[i][j] > dui[r])
            {
                lm[i][j] = 0;
            }
            else
            {
                while (l < r)
                {
                    int mid = (l + r) / 2;
                    if (dui[mid] >= lm[i][j])
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                if (dui[l] == lm[i][j])
                {
                    lm[i][j] = l;
                }
                else
                {
                    lm[i][j] = 0;
                }
            }
            gd[j][i] = gd[i][j];
            lm[j][i] = lm[i][j];
        }
    }
    for (int i = 1; i <= cnt && dui[i] <= n; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            for (int k = cnt; k >= j; k--)
            {
                f[gd[i][j]][lm[i][k]] = (f[gd[i][j]][lm[i][k]] + f[j][k]) % mod;
            }
        }
        f[i][i]++;
    }
    for (int i = 1; i <= cnt && dui[i] <= n; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            for (int k = j; k <= cnt; k++)
            {
                if (gd[i][j] == 1 && lm[i][k] == cnt)
                {
                    ans[i] = (ans[i] + f[j][k]) % mod;
                }
            }
        }
        ans[i] = 1ll * ans[i] * er % mod;
    }
    cin >> q;
    while (q--)
    {
        int x;
        x = kd();
        int l = 1, r = cnt;
        if (x < dui[l] || x > dui[r])
        {
            cout << 0 << endl;
        }
        else
        {
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (dui[mid] >= x)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if (dui[l] != x)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << ans[l] << endl;
            }
        }
    }
    return 0;
}