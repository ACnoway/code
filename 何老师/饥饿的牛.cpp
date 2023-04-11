#include <bits/stdc++.h>

using namespace std;

const int maxm = 2005;
int dp[maxm];

struct node
{
    int x;
    int y;
    int total;
};

bool cmp(node a , node b)
{
    return  a.y < b.y;
}

int main()
{
    int n;
    cin >> n;
    node s[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i].x >> s[i].y;
        s[i].total = s[i].y - s[i].x + 1; //计算区间元素个数
    }
    sort(s,s+n,cmp);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = s[n-1].y ; j >= s[i].y ; j--)
            dp[j] = max(dp[j],dp[s[i].x-1] + s[i].total);
    }
    cout << dp[s[n-1].y];
    return 0;
}

