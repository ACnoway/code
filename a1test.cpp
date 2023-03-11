#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#define int long long
using namespace std;
const int N = 500003;
int n, sum;
string a[N], now[N], ans[N];
int m[N];
map<char, int> chu, ru;
int flag, vis[N];
void dfs(int bef, int step)
{
    if (flag == 1)
        return;
    if (step == n)
    {
        flag = 1;
        for (int i = 1; i <= sum; ++i)
            ans[i] = now[i];
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == 1)
            continue;
        if (a[bef][a[bef].length()-1] == a[i][0])
        {
            now[++sum] = a[i];
            vis[i] = 1;
            dfs(i, step + 1);
            sum--;
            vis[i] = 0;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        m[i] = a[i].length();
        chu[a[i][0]]++;
        ru[a[i][m[i]-1]]++;
    }
    int st = 1;
    sort(a + 1, a + 1 + n);
    char s, t;
    for (char i = 'a'; i <= 'z'; ++i)
    {
        if (abs(chu[i] - ru[i]) == 1)
        {
            if (chu[i] - ru[i] == 1)
                s = i;
            else if (ru[i] - chu[i] == 1)
                t = i;
        }
    }
    int cnt = ru[t];
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][0] == s && (a[i][m[i]-1] != t || cnt != 1))
        {
            st = i;
            break;
        }
    }
    vis[st] = 1;
    now[++sum] = a[st];
    dfs(st, 1);
    if (flag == 0)
    {
        cout << "***" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << ".\n"[i == n];
    }
    return 0;
}