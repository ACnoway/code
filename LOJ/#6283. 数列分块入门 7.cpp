#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int maxn=100005,mod=10007;
int n,siz,sum;
int a[maxn],bl[maxn],jia[maxn],cheng[maxn],g[maxn][2];
inline void add(int l,int r,int c){
    for(int i=g[bl[l]][0];i<=g[bl[l]][1];++i){
        a[i]=a[i]*cheng[bl[l]]+jia[bl[l]]+(l<=i&&i<=r?c:0);
        a[i]%=mod;
    }
    cheng[bl[l]]=1;
    jia[bl[l]]=0;
    if(bl[l]!=bl[r]){
        for(int i=g[bl[r]][0];i<=g[bl[r]][1];++i){
            a[i]=a[i]*cheng[bl[r]]+jia[bl[r]]+(l<=i&&i<=r?c:0);
            a[i]%=mod;
        }
        cheng[bl[r]]=1;
        jia[bl[r]]=0;
    }
    for(int i=bl[l]+1;i<=bl[r]-1;++i) jia[i]+=c,jia[i]%=mod;
}
inline void mul(int l,int r,int c){
    for(int i=g[bl[l]][0];i<=g[bl[l]][1];++i){
        a[i]=((a[i]*cheng[bl[l]])%mod+jia[bl[l]]%mod)%mod*(l<=i&&i<=r?c:1);
        a[i]%=mod;
    }
    cheng[bl[l]]=1;
    jia[bl[l]]=0;
    if(bl[l]!=bl[r]){
        for(int i=g[bl[r]][0];i<=g[bl[r]][1];++i){
            a[i]=((a[i]*cheng[bl[r]])%mod+jia[bl[r]]%mod)%mod*(l<=i&&i<=r?c:1);
            a[i]%=mod;
        }
        cheng[bl[r]]=1;
        jia[bl[r]]=0;
    }
    for(int i=bl[l]+1;i<=bl[r]-1;++i){
        cheng[i]*=c,cheng[i]%=mod;
        jia[i]*=c,jia[i]%=mod;
    }
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
        cheng[i]=1;
        for(int j=g[i][0];j<=g[i][1];++j) bl[j]=i;
    }
    int op,l,r,c;
    for(int i=1;i<=n;++i){
        op=read();l=read();r=read();c=read();
        if(op==0) add(l,r,c%mod);
        else if(op==1) mul(l,r,c%mod);
        else write(((a[r]*cheng[bl[r]])%mod+jia[bl[r]]%mod)%mod),putchar('\n');
    }
    return 0;
}