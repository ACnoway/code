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
const int N=50004;
int n,m,len,siz,qc,sum;
int a[N],bl[N],g[N][2],ans[N],cntl[N],cntr[N];
struct wenti{
    int l,r,id,d;
    bool operator <(const wenti &x)const{
        return (bl[l]^bl[x.l])?bl[l]<bl[x.l]:(bl[l]&1)?r<x.r:r>x.r;
    }
}q[N<<2];
int main()
{
    n=read();
    len=sqrt(n);
    siz=n/len;
    if(len*siz<n) ++siz;
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=siz;++i){
        g[i][0]=(i-1)*len+1;
        g[i][1]=min(n,i*len);
        for(int j=g[i][0];j<=g[i][1];++j) bl[j]=i;
    }
    m=read();
    for(int i=1;i<=m;++i){
        int l1=read(),r1=read(),l2=read(),r2=read();
        q[++qc]={r1,r2,i,1};
        q[++qc]={r1,l2-1,i,-1};
        q[++qc]={l1-1,r2,i,-1};
        q[++qc]={l1-1,l2-1,i,1};
    }
    for(int i=1;i<=qc;++i){
        if(q[i].l>q[i].r) swap(q[i].l,q[i].r);
    }
    sort(q+1,q+qc+1);
    int l=0,r=0;
    for(auto i:q){
        while(l<i.l) sum+=cntr[a[++l]],++cntl[a[l]];
        while(l>i.l) sum-=cntr[a[l]],--cntl[a[l--]];
        while(r<i.r) sum+=cntl[a[++r]],++cntr[a[r]];
        while(r>i.r) sum-=cntl[a[r]],--cntr[a[r--]];
        ans[i.id]+=sum*i.d;
    }
    for(int i=1;i<=m;++i){
        printf("%d\n",ans[i]);
    }
    return 0;
}