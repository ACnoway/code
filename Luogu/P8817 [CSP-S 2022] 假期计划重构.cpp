#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=2502;
int n,m,k,u,v;
int a[N],dis[N];
vector<int> f[N],g[N];
bool can[N][N];
bool cmp(int x,int y){
    return a[x]>a[y];
}
void bfs(int x){
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    q.push(x);
    dis[x]=0;
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(u!=x){
            can[x][u]=1;
            if(x!=1&&can[1][u]){
                f[x].push_back(u);
                sort(f[x].begin(),f[x].end(),cmp);
                if(f[x].size()>3) f[x].pop_back();
            }
        }
        if(dis[u]>=k+1) continue;
        for(int to:g[u]){
            if(dis[to]==-1){
                dis[to]=dis[u]+1;
                q.push(to);
            }
        }
    }
}
signed main()
{
    n=read();m=read();k=read();
    for(int i=2;i<=n;++i) a[i]=read();
    for(int i=1;i<=m;++i){
        u=read();v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        bfs(i);
    }
    int ans=0;
    for(int b=2;b<=n;++b){
        for(int c=2;c<=n;++c){
            if(can[b][c]){
                for(int aa:f[b]){
                    for(int dd:f[c]){
                        if(aa!=c&&dd!=b&&aa!=dd){
                            ans=max(ans,a[aa]+a[b]+a[c]+a[dd]);
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}