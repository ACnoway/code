#include<cstdio>
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
int n,ans;
int a[9],f[9];
inline void dfs(int x,int y){
	if(f[x]>a[x]||f[x]+(n-y+1)*3<a[x]) return;
	if(x==n&&a[x]==f[x]){
		++ans;
		return;
	}
	if(y==n){
		int tmp=a[x]-f[x];
		if(tmp==2) return;
		int num=(!tmp?3:(tmp==1?1:0));
		f[y]+=num;
		dfs(x+1,x+2);
		f[y]-=num;
		return;
	}
	f[x]+=3;
	f[y]+=0;
	dfs(x,y+1);
	f[x]-=3;
	f[y]-=0;
	
	f[x]+=1;
	f[y]+=1;
	dfs(x,y+1);
	f[x]-=1;
	f[y]-=1;
	
	f[x]+=0;
	f[y]+=3;
	dfs(x,y+1);
	f[x]-=0;
	f[y]-=3;
	return;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	dfs(1,2);
	printf("%d\n",ans);
	return 0;
}
