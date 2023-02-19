#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int maxn=100005;
int n,siz,sum;
int a[maxn],bl[maxn],g[maxn][2],lt[maxn];
vector<int> v[502];
inline void add(int l,int r,int c){
    for(int i=l;i<=min(g[bl[l]][1],r);++i) a[i]+=c;
    v[bl[l]].clear();
    for(int i=g[bl[l]][0];i<=g[bl[l]][1];++i) v[bl[l]].push_back(a[i]);
    sort(v[bl[l]].begin(),v[bl[l]].end());
    if(bl[l]!=bl[r]){
        for(int i=g[bl[r]][0];i<=min(r,n);++i) a[i]+=c;
        v[bl[r]].clear();
        for(int i=g[bl[r]][0];i<=g[bl[r]][1];++i) v[bl[r]].push_back(a[i]);
        sort(v[bl[r]].begin(),v[bl[r]].end());
    }
    for(int i=bl[l]+1;i<=bl[r]-1;++i) lt[i]+=c;
}
inline void query(int l,int r,int c){
    int cn=c,ans=-2147483647;
    cn-=lt[bl[l]];
    for(int i=l;i<=min(g[bl[l]][1],r);++i) if(cn>a[i]) ans=max(ans,a[i]+lt[bl[l]]);
    if(bl[l]!=bl[r]){
        cn=c-lt[bl[r]];
        for(int i=g[bl[r]][0];i<=r;++i) if(cn>a[i]) ans=max(ans,a[i]+lt[bl[r]]);
    }
    for(int i=bl[l]+1;i<=bl[r]-1;++i){
        cn=c-lt[i];
        auto x=lower_bound(v[i].begin(),v[i].end(),cn);
        if(x!=v[i].begin()) ans=max(ans,*prev(x)+lt[i]);
    }
    if(ans!=-2147483647) write(ans);
    else write(-1);
    putchar('\n');
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    siz=sqrt(n),sum=n/siz;
    if(siz*sum<n) sum++;
    for(int i=1;i<=sum;++i){
        g[i][0]=(i-1)*siz+1;
        g[i][1]=min(n,i*siz);
        for(int j=g[i][0];j<=g[i][1];++j) bl[j]=i,v[i].push_back(a[j]);
        sort(v[i].begin(),v[i].end());
    }
    int op,l,r,c;
    for(int i=1;i<=n;++i){
        op=read();l=read();r=read();c=read();
        if(op==0) add(l,r,c);
        else query(l,r,c);
    }
    return 0;
}