#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define int long long
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
const int N=100005;
typedef pair<int,int> pii;
int T,n,m,p;
int a[N],b[N];
bool vis[N];
vector<int> e[N];
void bfs(int s){
    queue<pii> q;
    vis[s]=1;
    a[s]=b[s];
    q.emplace((pii){s,a[s]});
    while(!q.empty()){
        auto now=q.front();
        q.pop();
        int u=now.first,w=now.second;
        for(int v:e[u]){
            if(vis[v]) continue;
            vis[v]=1;
            q.emplace((pii){v,(w+1)%p});
            a[v]=(w+1)%p;
        }
    }
}
signed main()
{
    freopen("distance.in","r",stdin);
    freopen("distance.out","w",stdout);
    T=read();
    while(T--){
        n=read(); m=read();
        p=read();
        for(int i=0;i<=n;++i){
            e[i].clear();
            vis[i]=0;
        }
        for(int i=1;i<=m;++i){
            int u=read(),v=read();
            if(u==v) continue;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;++i) b[i]=read();
        int cnt=0,pi=1;
        bool flag=1;
        for(int i=1;i<=n;++i){
            flag=1;
            for(int v:e[i]){
                if((b[i]+1)%p!=b[v]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                pi=i;
                ++cnt;
            }
        }
        if(cnt!=1){
            cout<<"zkyakioi"<<endl;
            continue;
        }
        bfs(pi);
        flag=1;
        for(int i=1;i<=n;++i){
            if(a[i]!=b[i]){
                flag=0;
                break;
            }
        }
        if(flag) cout<<pi<<endl;
        else cout<<"zkyakioi"<<endl;
    }
    return 0;
}