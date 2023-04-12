#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
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
const int N=2e5+10;
int T,n,m,cnt,tmp[6];
int qu[N<<2],b[N<<1],du[N<<2],vis[N<<2],c[N<<2],rk[N<<2];
bool flag;
vector<int> e[N<<2],g[N<<2];
map<int,int> mp;
struct edge{
    int u,v;
};
vector<edge> bian;
bool cmp(int x,int y){
    if(du[x]==du[y]) return x<y;
    return du[x]<du[y];
}
signed main()
{
    T=read();
    while(T--){
        n=read();
        
        //多测不清空，_____
        cnt=n;
        for(int i=1;i<=(n<<2);++i){
            e[i].clear();
            g[i].clear();
            du[i]=0;
            vis[i]=0;
            c[i]=i;
            qu[i]=0;
        }
        mp.clear();
        bian.clear();
        flag=0;
        
        for(int i=1;i<=n;++i){
            m=read();
            for(int j=1;j<=m;++j){
                int x=read();
                if(!mp[x]) mp[x]=++cnt;
                x=mp[x];
                bian.push_back({i,x});
                e[i].push_back(x);
                e[x].push_back(i);
                ++du[i]; ++du[x];
            }
        }
        for(int i=1;i<=cnt;++i) rk[i]=(du[i]-1)*cnt+i;
        for(int i=1;i<=n;++i){
            for(int v:e[i]){
                if(rk[i]<rk[v]) g[i].push_back(v);
                else g[v].push_back(i);
            }
        }
        for(int i=1;i<=cnt;++i){
            for(int v:e[i]){
                for(int to:g[v]){
                    if(rk[to]>rk[i]){
                        if(qu[to]){
                            tmp[1]=qu[to]; tmp[2]=to;
                            tmp[3]=v; tmp[4]=i;
                            sort(tmp+1,tmp+5);
                            printf("%lld %lld\n",tmp[1],tmp[2]);
                            flag=1;
                            break;
                        }
                        else qu[to]=v;
                    }
                }
                if(flag) break;
            }
            for(int v:e[i]){
                for(int to:g[v]){
                    if(rk[to]>rk[i]) qu[to]=0;
                }
            }
            if(flag) break;
        }
        for(int i=1;i<=cnt;++i) e[i].clear(),g[i].clear(),qu[i]=0;
        if(flag) continue;
        else printf("-1\n");
    }
    return 0;
}