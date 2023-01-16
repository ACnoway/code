#include <bits/stdc++.h>
using namespace std;
int n,k,sz[10000010],sf[10000010],a[10000010],szero[10000010],ans = -1000000000,i,j = 1,mn = 1000000000,q[10000010],l,r;
int main()
{
    freopen("p8945.in","r",stdin);
    freopen("p8945.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(i = 1;i <= n;i++)
	{
		cin >> a[i];
		szero[i] = szero[i - 1];
		if(a[i] == 1)
		{
			sz[i] = sz[i - 1] + 1;
			sf[i] = sf[i - 1] + 1;
		}else if(a[i] == 0)
		{
			sz[i] = sz[i - 1] + 1;
			sf[i] = sf[i - 1] - 1;
			szero[i]++;
		}else{
			sz[i] = sz[i - 1] - 1;
			sf[i] = sf[i - 1] - 1;
		}
	}
	l = 1;
	for(i = 1;i <= n;i++)
	{
		int p = i;
		while(l <= r && szero[i] - szero[q[l] - 1] > k)
		{
			l++;
		}
		while(l <= r && sz[p - 1] <= sz[q[r] - 1])
		{
			r--;
		}
		q[++r] = p;
		if(l <= r)
		{
			ans = max(ans,sz[i] - sz[q[l] - 1]);
		}
		while(szero[i] - szero[j - 1] >= k)
		{
			mn = min(mn,sf[j - 1]);
			j++;
		}
		ans = max(ans,sf[i] - mn + 2 * k);
	}
	cout << ans;
    return 0;
}
