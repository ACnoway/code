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
const int N=51;
int n,m,l,sum;
string s,a[N];
bool vis[N];
void dfs(int x){
	if(x>n){
		string ans="0000000000000000000000000000000000000000";
		for(int i=1;i<=n;++i){
			if(vis[i]){
				for(int j=0;j<m;++j){
					if(ans[j]!=a[i][j]) ans[j]='1';
					else ans[j]='0';
				}
			}
		}
		if(ans.find(s)!=-1) ++sum;
		return;
	}
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	cin>>l;
	cin>>s;
	dfs(1);
	printf("%d\n",sum);
	return 0;
}
