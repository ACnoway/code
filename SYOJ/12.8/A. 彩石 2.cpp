#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
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
const int N=1000006,K=62;
int n,k;
int cnt[K],p[K];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
int main()
{
    n=read();
    k=read();
    for(int i=1;i<=k;++i){
        int x=read();
        for(int j=1;j<=x;++j){
            int xx=read();
            q.emplace(xx,i);
        }
    }
    int ans=(1<<31-1),l=(1<<31-1),r=0,now=0;
    while(!q.empty()){
        int x=q.top().first,u=q.top().second;
        q.pop();
        if(!cnt[u]) ++cnt[u],++now;
        p[u]=x;
        if(now<k) continue;
        l=(1<<31-1),r=0;
        for(int i=1;i<=k;++i){
            l=min(l,p[i]);
            r=max(r,p[i]);
        }
        ans=min(ans,r-l);
    }
    printf("%d\n",ans);
    return 0;
}
