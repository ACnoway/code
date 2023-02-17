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
const int maxn=50004;
int n,siz,sum;
int a[maxn],bl[maxn],g[maxn][2],lt[maxn];
vector<int> v[502];
inline void add(int l,int r,int c){
    for(int i=l;i<=min(bl[l]*siz,r);++i) a[i]+=c;
    if(bl[l]!=bl[r]){
        for(int i=(bl[r]-1)*siz+1;i<=min(r,n);++i) a[i]+=c;
    }
    for(int i=bl[l]+1;i<=bl[r]-1;++i) lt[i]+=c;
}
inline void query(int l,int r,int c){
    int cn=c,ans=0;
    cn-=lt[bl[l]];
    for(int i=l;i<=min(bl[l]*siz,r);++i) if(cn>a[i]) ans++;
    if(bl[l]!=bl[r]){
        cn=c-lt[bl[r]];
        for(int i=(bl[r]-1)*siz+1;i<=r;++i) if(cn>a[i]) ans++;
    }
    for(int i=bl[l]+1;i<=bl[r]-1;++i){
        cn=c-lt[i];
        auto x=lower_bound(v[i].begin(),v[i].end(),cn);
        if(x!=v[i].begin()){
            ans+=x-v[i].begin();
        }
    }
    write(ans);
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
        g[i][1]=(n,i*siz);
        for(int j=g[i][0];j<=g[i][1];++j) bl[j]=i,v[i].push_back(a[j]);
        sort(v[i].begin(),v[i].end());
    }
    int op,l,r,c;
    for(int i=1;i<=n;++i){
        op=read();l=read();r=read();c=read();
        if(op==0) add(l,r,c);
        else query(l,r,c*c);
    }
    return 0;
}