#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
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
const int N=3003;
int e[N][N];
int n,m,ans=1145141919;
bool vis[N];
typedef pair<int,int> pii;
void bfs(){
    queue<pii> q;
    pii now;
    q.push({1,0});
    vis[1]=1;
    while(!q.empty()){
        now=q.front();
        q.pop();
        int u=now.first,sp=now.second+1;
        for(int i=1;i<n;++i){
            if(e[u][i]&&!vis[i]) q.push({i,sp}),vis[i]=1;
        }
        if(e[u][n]){
            ans=min(ans,sp);
            continue;
        }
    }
}
void bfs1(){
    queue<pii> q;
    pii now;
    q.push({1,0});
    vis[1]=1;
    while(!q.empty()){
        now=q.front();
        q.pop();
        int u=now.first,sp=now.second+1;
        for(int i=1;i<n;++i){
            if(!e[u][i]&&!vis[i]) q.push({i,sp}),vis[i]=1;
        }
        if(!e[u][n]){
            ans=min(ans,sp);
            continue;
        }
    }
}
int main()
{
    n=read();
    m=read();
    for(int i=0;i<m;++i){
        int u,v;
        u=read();
        v=read();
        e[u][v]=e[v][u]=1;
    }
    if(e[1][n])
        bfs1();
    else
        bfs();
    if(ans==1145141919){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",ans);
    return 0;
}