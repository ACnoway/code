#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
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
const int N=300005,A=1000006;
int n,m,cnt;
ll a[N];
ll d[A+10],num[A+10],ps[A+10];
bool vis[A+10];
//* -----并查集
ll p[N];
ll find(int x){
    while(p[x]!=x) x=p[x]=p[p[x]];
    return p[x];
}
void merge(int x,int y){
    p[find(x)]=find(y);
}
//* -----树状数组
ll tree[N<<2];
inline int lowbit(int x){
    return x&(-x);
}
inline void add(int x,int k){
    for(;x<=n;x+=lowbit(x)){
        tree[x]+=k;
    }
}
inline ll query(int x){
    ll sum=0;
    for(;x;x-=lowbit(x)){
        sum+=tree[x];
    }
    return sum;
}
void init(){
    d[1]=1;
    for(ll i=2;i<A;++i){
        if(!vis[i]){
            vis[i]=1;
            ps[++cnt]=i;
            d[i]=2ll;
            num[i]=1ll;
        }
        for(int j=1;j<=cnt&&i*ps[j]<A;++j){
            vis[i*ps[j]]=1ll;
            if(i%ps[j]==0ll){
                num[i*ps[j]]=num[i]+1ll;
                d[i*ps[j]]=d[i]/num[i*ps[j]]*(num[i*ps[j]]+1ll);
                break;
            }
            num[i*ps[j]]=1ll;
            d[i*ps[j]]=d[i]*2ll;
        }
    }
}
signed main()
{
    init();
    n=read();m=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        add(i,a[i]);
        p[i]=i;
    }
    p[n+1]=n+1;
    int k,l,r;
    while(m--){
        k=read();
        l=read();
        r=read();
        if(l>r) swap(l,r);
        if(k==1){
            for(int i=l;i<=r;){
                add(i,d[a[i]]-a[i]);
                a[i]=d[a[i]];
                if(a[i]<=2){
                    p[i]=i+1ll;
                }
                if(i==find(i)) i++;
                else i=p[i];
            }
        }
        else printf("%lld\n",query(r)-query(l-1));
    }
    return 0;
}