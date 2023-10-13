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
const int N=1003;
int n,m,t;
int ru[N],st[N];
int a[N][N],mp[N][N];
bool vis[N];
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;++i){
		a[i][0]=read();
		for(int j=0;j<=n;++j) vis[j]=0;
		for(int j=1;j<=a[i][0];++j) a[i][j]=read(),vis[a[i][j]]=1;
		for(int j=a[i][1];j<=a[i][a[i][0]];++j){
			if(!vis[j])
				for(int k=1;k<=a[i][0];++k)
					if(!mp[j][a[i][k]]) mp[j][a[i][k]]=1,++ru[a[i][k]];
		}
	}
	for(int i=1;i<=n;++i) vis[i]=0;
	int ans=0;
	do{
		t=0;
		for(int i=1;i<=n;++i){
			if(!ru[i]&&!vis[i]){
				st[++t]=i;
				vis[i]=1;
			}
		}
		for(int i=1;i<=t;++i){
			for(int j=1;j<=n;++j){
				if(mp[st[i]][j]) mp[st[i]][j]=0,ru[j]--;
			}
		}
		++ans;
	}while(t);
	printf("%d\n",ans-1);
	return 0;
}
