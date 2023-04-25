#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
typedef pair<int,int> pii;
const int N=2003;
int n,m,q;
int a[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool vis[N][N];
void bfs(int sx,int sy){
    queue<pii> nxt;
    pii p;
    nxt.emplace((pii){sx,sy});
    vis[sx][sy]=1;
    while(!nxt.empty()){
        p=nxt.front();
        nxt.pop();
        int x=p.first,y=p.second;
        for(int i=0;i<4;++i){
            int xx=x+dx[i],yy=y+dy[i];
            if(!vis[xx][yy]&&a[x][y]==a[xx][yy]){
                vis[xx][yy]=1;
                nxt.emplace((pii){xx,yy});
            }
        }
    }
}
int main()
{
    n=read();
    m=read();
    q=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            char x=getchar();
            while(x<'a'||x>'z') x=getchar();
            a[i][j]=x-'a'+1;
        }
    }
    while(q--){
        int xa=read(),ya=read(),xb=read(),yb=read(),ans=0;
        for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) vis[i][j]=0;
        for(int i=xa;i<=xb;++i){
            for(int j=ya;j<=yb;++j){
                if(!vis[i][j]){
                    bfs(i,j);
                    ++ans;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}