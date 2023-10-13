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
const int N=300005;
int n;
int nxt[N],vis[N];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) nxt[i]=read(),vis[i]=-1;
	int ans=1<<30,cnt=0;
	for(int i=1;i<=n;++i){
		if(vis[i]==-1){
			vis[i]=cnt++;
			for(int j=nxt[i];j;j=nxt[j]){
				if(vis[j]==-1) vis[j]=cnt++;
				else if(vis[j]<vis[i]) break;
				else if(vis[j]>=vis[i]){
					ans=min(ans,cnt-vis[j]);
					break;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
