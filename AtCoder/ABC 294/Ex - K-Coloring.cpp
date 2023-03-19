#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
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
const int N=50;
int n,m,k;
int color[N];
bool vis[N];
vector<int> e[N];
void bfs(int st){
    int p,mex;
    queue<int> q;
    q.push(st);
    vis[st]=1;
    while(!q.empty()){
        mex=1;
        p=q.front();
        q.pop();
        for(auto v:e[p]){
            vis[v]=1;
            if(!color[v]){
                q.push(v);
            }
            else{
                if(color[v]==mex) mex++;
            }
        }
        color[p]=mex;
    }
}
int main()
{
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ma=0;
    long long ans=1;
    for(int i=1;i<=n;++i){
        if(!vis[i]) bfs(i);
        ma=0;
        for(int j=1;j<=n;++j){
            ma=max(ma,color[j]);
            if(color[j]) color[j]=0;
        }
        if(ma<=k){
            for(int j=1;j<=ma;++j){
                ans*=(k-j+1);
                ans%=998244353;
            }
        }
    }
    printf("%lld\n",ans);
    
    return 0;
}