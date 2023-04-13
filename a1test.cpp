#include <iostream>
#define int long long
using namespace std;
int ans, n, a[45], f[45][45][2345][2];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (a[1] != -1)
        f[1][a[1]][a[1]][0] = 1;
    else
        for (int i = 0; i <= 40; i++)
            f[1][i][i][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        int l = 0, r = 40;
        if (a[i] != -1)
            l = r = a[i];
        for (int o = l; o <= r; o++)
            for (int j = o * (i - 1); j < 2023; j++)
            {
                for (int k = 0; k <= o; k++)
                    f[i][o][j + o][0] = (f[i][o][j + o][0] + f[i - 1][k][j][0] + f[i - 1][k][j][1]) % 1000000007;
                for (int k = o + 1; k <= 40; k++)
                    f[i][o][j + o][1] = (f[i][o][j + o][1] + f[i - 1][k][j][0]) % 1000000007;
            }
    }
    for (int i = 0; i <= 40; i++)
        for (int j = 0; j <= 40 * n; j++)
            ans = (ans + f[n][i][j][0] + f[n][i][j][1]) % 1000000007;
    cout << ans;
}