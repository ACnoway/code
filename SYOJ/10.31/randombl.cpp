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
int n,cnt,sum;
int tong[10000];
bool vis[10000];
void dfs(int x,int s){
	if(x>=n){
		sum+=s+1;
		++cnt;
		for(int i=0;i<=n;++i) if(vis[i]) cout<<i<<' ';
		cout<<endl;
		cout<<"s="<<s+1<<endl<<endl;
		tong[s+1]++;
		return;
	}
	vis[x]=1;
	dfs(x+1,s+1);
	vis[x]=0;
	dfs(x+1,s);
}
int main()
{
	n=read();
	vis[0]=vis[n]=1;
	dfs(1,0);
	for(int i=0;i<=10;++i){
//		cout<<"i="<<i<<" cnt="<<tong[i]<<endl;
		for(int j=0;j<(tong[i]>>1);++j) putchar('-');
		putchar('\n');
	}
	printf("%.6lf\n",(double)sum/(double)cnt);
	return 0;
}
