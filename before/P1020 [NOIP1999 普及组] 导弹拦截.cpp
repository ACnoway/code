#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[100001],dp[100001];
int main()
{
	int miscnt=0,ans1=0,ans2=0;
	while(cin>>a[++miscnt]);
	miscnt--;
	for(int i=miscnt;i>=1;i--){
		dp[i]=1;
		for(int j=i+1;j<=miscnt;j++){
			if(a[j]<=a[i])
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans1=max(ans1,dp[i]);
	}
	int ans,f[100010];
    f[0]=0; ans=0;
    for(int i=1; i<=n; i++)
    {
        if (a[i]>f[ans]) f[++ans]=a[i];
        else
        {
            int k=lower_bound(f,f+ans+1,a[i])-f;
            f[k]=a[i];
        }
    }
	for(int i=miscnt;i>=1;i--){
		dp[i]=1;
		for(int j=i+1;j<=miscnt;j++){
			if(a[j]>a[i])
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans2=max(ans2,dp[i]);
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}

