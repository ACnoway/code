#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=1000006,M=1000006,mod=998244353;
int ksm(int a,int b){
    int res=1;
    while(b){
        if(b&1) res*=a,res%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return res;
}
typedef pair<int,int> pii;
int n,m;
int ans[N];
int hd,tl;
int du[N],q[N];
vector<pii> e[N];
bool huan[N],vis[N];
void tuopu(){
    hd=tl=0;
    for(int i=1;i<=n;++i) if(!du[i]) q[++tl]=i;
    int p,v;
    while(hd<tl){
        p=q[++hd];
        for(pii i:e[p]){
            v=i.second;
            --du[v];
            if(!du[v]) q[++tl]=v;
        }
    }
}
int main()
{
    // freopen("number.in","r",stdin);
    // freopen("number.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read(),w=read();
        ++du[v];
        e[u].emplace_back((pii){w,v});
    }
    for(int i=1;i<=n;++i) sort(e[i].begin(),e[i].end());
    tuopu();
    return 0;
}