#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=100,P=10007;
int n,cnt,ans;
int a[N];
void dfs(int x){
	if(x>n){
		bool flag=1;
//		cout<<"--------------\n"<<++cnt<<"--------------"<<endl;
		for(int i=1;i+2<=n;++i){
			if(a[i]==1&&a[i+2]==1){
				flag=0;
				break;
			}
//			cout<<a[i]<<' ';
		}
		if(flag) ++ans,ans%=P;
//		cout<<endl;
		return;
	}
	dfs(x+1);
	a[x]=1;
	dfs(x+1);
	a[x]=0;
}
int main()
{
//	freopen("queue.in","r",stdin);
//	freopen("queue.out","w",stdout);
	for(int i=1;i<=30;++i){
		n=i;
		ans=0;
		dfs(1);
		printf("%d\n",ans);
	}
	
	return 0;
}
