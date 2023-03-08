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
const int N=300005;
int t,n,top;
int h[N],f[N],st[N],zuo[N],you[N];
signed main()
{
    t=read();
    while(t--){
        n=read();
        top=0;
        for(int i=1;i<=n;++i){
            h[i]=read();
            f[i]=f[i-1]+h[i];
            zuo[i]=you[i]=0;
        }
        int l,r;
        st[++top]=1;
        for(int i=2;i<=n;++i){
            if(h[i]>h[i-1]) zuo[i]=zuo[i-1];
            else{
                while(top&&h[st[top]]-st[top]>h[i]-i) top--;
                l=st[top];
                //加上之前的
                zuo[i]+=zuo[l];
                //加上中间的
                zuo[i]+=f[i]-f[l];
                //减去最后的
                zuo[i]-=(h[i]+h[i]-min(i-l,h[i])+1)*min(h[i],i-l)>>1;
            }
            st[++top]=i;
        }
        reverse(h+1,h+n+1);
        for(int i=1;i<=n;++i) f[i]=f[i-1]+h[i];
        top=0;
        st[++top]=1;
        for(int i=2;i<=n;++i){
            if(h[i]>h[i-1]) you[i]=you[i-1];
            else{
                while(top&&h[st[top]]-st[top]>h[i]-i) top--;
                l=st[top];
                //加上之前的
                you[i]+=you[l];
                //加上中间的
                you[i]+=f[i]-f[l];
                //减去最后的
                you[i]-=(h[i]+h[i]-min(i-l,h[i])+1)*min(h[i],i-l)>>1;
            }
            st[++top]=i;
        }
        int ans=LONG_LONG_MAX,ap;
        for(int i=1;i<=n;++i){
            ans=min(ans,zuo[n-i+1]+you[i]+h[i]);
        }
        //debug(ans);
        
        printf("%lld\n",ans);
    }
    return 0;
}