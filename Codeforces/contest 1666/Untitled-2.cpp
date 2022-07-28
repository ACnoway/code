#include<iostream>
#include<queue>
#define MAXN 200005
#define MAXM 200005
using namespace std;
int fst[MAXN],nt[MAXM],to[MAXM];
int lst[MAXN],peo[MAXN];
int ans[MAXN];
struct zt{
	int x,p;
};
zt nw(int a,int b){
	zt us;
	us.x=a;
	us.p=b;
	return us;
}
queue<zt>q;
int main(){
	int n,m,s;
	cin>>n>>m>>s;
	int x,p,i,u;
	for(i=1;i<=m;++i){
		cin>>u>>p;
		nt[i]=fst[u];
		to[i]=p;
		fst[u]=i;
	}
	u=0;
	for(i=fst[s];i;i=nt[i]){
		q.push(nw(to[i],++u));
		lst[to[i]]=s;
	}
	while(!q.empty()){
		x=q.front().x;
		p=q.front().p;
		for(i=fst[x];i;i=nt[i]){
			if(to[i]==s||peo[to[i]]==p)continue;
			if(!peo[to[i]]){
				peo[to[i]]=p;
				lst[to[i]]=x;
				q.push(nw(to[i],p));
				continue;
			}
			if(peo[to[i]]!=p){
				p=n;
				cout<<"Possible"<<endl;
				for(u=to[i];u;u=lst[u])ans[p--]=u;
				cout<<n-p<<endl;
				for(;p<n;)cout<<ans[++p]<<' ';
				for(u=x;u;u=lst[u])ans[p--]=u;
				cout<<endl<<n-p+1<<endl;
				for(;p<n;)cout<<ans[++p]<<' ';
				cout<<to[i]<<endl;
				return 0;
			}
		}
		q.pop();
	}
	cout<<"Impossible"<<endl;
	return 0;
}