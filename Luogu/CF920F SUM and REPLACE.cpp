#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=300005,A=1000006;
int n,m;
int a[N],d[A];
//* -----并查集
int p[N];
int find(int x){
    while(p[x]!=x) x=p[x]=p[p[x]];
    return p[x];
}
void merge(int x,int y){
    p[find(x)]=find(y);
}
//* -----树状数组
int tree[N<<2];
inline int lowbit(int x){
    return x&(-x);
}
inline void add(int x,int k){
    for(;x<=n;x+=lowbit(x)){
        tree[x]+=k;
    }
}
inline int query(int x){
    int sum=0;
    for(;x;x-=lowbit(x)){
        sum+=tree[x];
    }
    return sum;
}
signed main()
{
    for(int i=1;i<A;++i){
        for(int j=i;j<A;j+=i){
            d[j]++;
        }
    }
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
                    p[i]=i+1;
                }
                if(i==find(i)) i++;
                else i=p[i];
            }
        }
        else printf("%lld\n",query(r)-query(l-1));
    }
    return 0;
}