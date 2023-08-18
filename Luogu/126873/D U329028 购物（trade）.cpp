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
const int N=1e5+10;
int n,m;
int a[N],pre[N],nxt[N],f[N],pre1[N],nxt1[N],f1[N];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int op,x,y,ans,st;
    if(n<=1000&&m<=1000){
        while(m--){
            op=read();
            x=read(); y=read();
            if(op==1){
                if(x<y){
                    ans=0; st=x;
                    for(int i=x+1;i<=y;++i)
                        if(a[i]<a[i-1])
                            ans+=a[i-1]-a[st],st=i;
                    printf("%d\n",ans);
                }
                else{
                    ans=0; st=x;
                    for(int i=x-1;i>=y;--i)
                        if(a[i]<a[i+1])
                            ans+=a[i+1]-a[st],st=i;
                    printf("%d\n",ans);
                }
            }
            else a[x]=y;
        }
        return 0;
    }
    int st=1;
    st=1;
    for(int i=1;i<=n;++i){
        if(a[i]>a[i+1]) st=i;
        pre[i]=st;
    }
    st=n;
    for(int i=n-1;i;--i){
        if(a[i]>a[i+1]) st=i;
        nxt[i]=st;
    }
    st=1;
    for(int i=2;i<=n;++i){
        if(a[i]>a[i-1]) st=i;
        pre1[i]=st;
    }
    st=n;
    for(int i=n;i;--i){
        if(a[i]>a[i-1]) st=i;
        nxt1[i]=st;
    }
    st=1;
    for(int i=nxt[1];i<=n;i=nxt[i]){
        f[i]=a[i]-a[st];
        st=i+1;
        // pref[i]+=pref[i+1];
    }
    for(int i=n;i;--i) f[i]+=f[i+1];
    st=1;
    for(int i=nxt[1];i;i=nxt[i]){
        nxtf[i]=a[i]-a[st];
        st=i+1;
        // nxtf[i]+=nxtf[i+1];
    }
    for(int i=1;i<=n;++i) nxtf[i]+=nxtf[i-1];
    while(m--){
        op=read();
        x=read(); y=read();
        if(op==1){
            if(x<y){
                ans=0;
                ans+=a[nxt[x]]-a[x];
                ans+=nxtf[pre[y]]
                printf("%d\n",ans);
            }
            else{
                ans=0; st=x;
                for(int i=x-1;i>=y;--i)
                    if(a[i]<a[i+1])
                        ans+=a[i+1]-a[st],st=i;
                printf("%d\n",ans);
            }
        }
        else a[x]=y;
    }
    return 0;
}