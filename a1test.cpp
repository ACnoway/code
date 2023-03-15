#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i, j, k, n, m, t, r1, r2, f1, f2;

int main()
{
    ios::sync_with_stdio(0);
    cin >> t >> n;
    for (int T = 1; T <= t; T++)
    {
        string f;
        cin >> f;

        for (auto &i : f)
        {
            i -= '0';
        }
        f = "$" + f;

        f1 = n / 2;
        f2 = n / 4;
        for (i = 1; i <= n; i++)
        {
            if (i < n && f2 && (f[i] + f[i + 1] == 2))
            {
                r1 += (f[i] || f[i + 1]);
                f2--;
                i++;
            }
            else
            {
                r1 += f[i];
            }
        }

        f1 = n / 2;
        f2 = n / 4;
        for (i = 1; i <= n; i++)
        {
            if (i < n && f2 && (f[i] + f[i + 1] != 2))
            {
                r2 += (f[i] || f[i + 1]);
                f2--;
                i++;
            }
            else
            {
                r2 += f[i];
            }
        }
        r2 -= f2;
    }
    cout << r1 << ' ' << r2;
}