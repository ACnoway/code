#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int k,n,m,cnt;
double ans;
int t[1000006];
signed main()
{
	cin>>k>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int x=1;x<=i;++x){
				for(int y=1;y<=j;++y){
					++t[abs(i-x+1)*abs(j-y+1)];
					++cnt;
				}
			}
		}
	}
	for(int i=1;i<=n*m;++i){
		if(!t[i]) continue;
		cout<<i<<' '<<t[i]<<endl;
		ans+=(double)(i*t[i]);
	}
	printf("%.8lf\n",ans/(double)cnt);
	return 0;
}
