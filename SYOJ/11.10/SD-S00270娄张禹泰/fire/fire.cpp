#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=300005;
int n,q;
int idx,head[N],nxt[N],to[N],w[N];
long long ans=0;
inline void add(int u,int v,int _w){
    to[++idx]=v;
    w[idx]=_w;
    nxt[idx]=head[u];
    head[u]=idx;
}
int h,t;
int que[N];
inline void bfs(int x,int k){
    h=t=0;
    que[++t]=x;
    int u,v;
    while(h<t){
        u=que[++h];
        for(int i=head[u];i;i=nxt[i]){
            v=to[i];
            if(w[i]<=k){
                que[++t]=v;
                ans+=w[i];
            }
        }
    }
}
long long juhua_pai[N],juhua_sum[N];
int main()
{
    freopen("fire.in","r",stdin);
    freopen("fire.out","w",stdout);
    n=read();
    bool juhua=1;
    for(int i=2;i<=n;++i){
        int u=read(),_w=read();
        add(u,i,_w);
        if(u!=1) juhua=0;
    }
    q=read();
    if(juhua){
        for(int i=1;i<=idx;++i) juhua_pai[i]=w[i];
        sort(juhua_pai+1,juhua_pai+1+idx);
        for(int i=1;i<=idx;++i) juhua_sum[i]=juhua_pai[i]+juhua_sum[i-1];
        while(q--){
            int u=read(),k=read();
            if(u!=1) printf("0\n");
            else{
                int p=upper_bound(juhua_pai+1,juhua_pai+1+idx,k)-juhua_pai-1;
                printf("%lld\n",juhua_sum[p]);
            }
        }
        return 0;
    }
    while(q--){
        int u=read(),k=read();
        ans=0;
        bfs(u,k);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
36
15
36
5
36
5
36
36
5
15

*/