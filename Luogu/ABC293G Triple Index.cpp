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
const int N=200005;
int n,q,len,cnt,sum;
int a[N],tong[N],ans[N];
int bl[N],g[N][2];
struct node{
    int l,r,p;
    bool operator <(const node &x)const{
        return (bl[l]^bl[x.l])?bl[l]<bl[x.l]:(bl[l]&1)?r<x.r:r>x.r;
    }
}b[N];
int calc(int x){return (x>1?(x*(x-1)>>1):0);}
signed main()
{
    n=read(); q=read();
    //计算块长和数量
    len=sqrt(n);
    cnt=n/len;
    if(len*cnt<n) ++cnt;
    
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    //记录块的边界和归属
    for(int i=1;i<=cnt;++i){
        g[i][0]=(i-1)*len+1;
        g[i][1]=i*len;
        for(int j=g[i][0];j<=g[i][1];++j) bl[j]=i;
    }
    //读入询问
    for(int i=1;i<=q;++i){
        b[i].l=read();
        b[i].r=read();
        b[i].p=i;
    }
    sort(b+1,b+1+q);
    int L=1,R=0;
    for(int i=1;i<=q;++i){
        while(L>b[i].l) sum+=calc(tong[a[--L]]++);
        while(L<b[i].l) sum-=calc(--tong[a[L++]]);
        while(R<b[i].r) sum+=calc(tong[a[++R]]++);
        while(R>b[i].r) sum-=calc(--tong[a[R--]]);
        ans[b[i].p]=sum;
    }
    for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
    return 0;
}