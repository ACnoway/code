#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100005;
int s,n,q,w,b1,b2,inc,de,l,h,op;
int a[N],f[N],ll[N],hh[N];
bool hs[N];
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
int main()
{
    s=read();
    n=read();
    q=read();
    w=read();
    b1=read();
    b2=read();
    inc=read();
    de=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int st,mi,en,ans;
    if(s==5){
        for(int i=1;i<=n;++i){
            if(abs(a[i]-w)<=b1) f[i]=inc;
            else if(abs(a[i]-w)<=b2) f[i]=0;
            else f[i]=de;
        }
        while(q--){
            op=read();
            if(op==1){
                ans=-0x3f3f3f;
                l=read();
                h=read();
                l=read();
                int le=1,re=1;
                int m=f[1],sum=f[1];

                for(int i=2;i<=n;++i){
                    if(m>0){
                        m+=a[i];
                        re=i;
                    }
                    else{
                        m=a[i];
                        le=i;
                    }
                    if(m>sum){
                        sum=m;
                    }
                    if(l>=le&&l<=re) ans=max(ans,m);
                }
                cout<<ans<<endl;
            }
            else{
                w=read();
                for(int i=1;i<=n;++i){
                    if(abs(a[i]-w)<=b1) f[i]=inc;
                    else if(abs(a[i]-w)<=b2) f[i]=0;
                    else f[i]=de;
                }
            }
        }
        return 0;
    }
    for(int i=1;i<=n;++i){
        if(abs(a[i]-w)<=b1) f[i]=inc;
        else if(abs(a[i]-w)<=b2) f[i]=0;
        else f[i]=de;
        f[i]+=f[i-1];
    }
    while(q--){
        op=read();
        if(op==1){
            ans=-0x3f3f3f;
            l=read();
            h=read();
            for(int i=0;i<=n;++i) hs[i]=0;
            for(int i=1;i<=l;++i) ll[i]=read();
            for(int i=1;i<=h;++i) hh[i]=read(),hs[hh[i]]=1;
            for(int i=1;i<=l;++i){
                mi=ll[i];
                st=mi;
                en=mi;
                while(!hs[st]&&st>0) st--;
                while(!hs[en]&&en<=n) en++;
                st++;en--;
                for(int j=st;j<=mi;++j){
                    for(int k=mi;k<=en;++k){
                        ans=max(ans,f[k]-f[j-1]);
                    }
                }
            }
            cout<<ans<<endl;
        }
        else{
            w=read();
            for(int i=1;i<=n;++i){
                if(abs(a[i]-w)<=b1) f[i]=inc;
                else if(abs(a[i]-w)<=b2) f[i]=0;
                else f[i]=de;
                f[i]+=f[i-1];
            }
        }
    }
    return 0;
}