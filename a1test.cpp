#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100005;
const int INF=2147483644;
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
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
    int st,mi,en,ans,tmp;
    for(int i=1;i<=n;++i){
        if(abs(a[i]-w)<=b1) f[i]=inc;
        else if(abs(a[i]-w)<=b2) f[i]=0;
        else f[i]=de;
        f[i]+=f[i-1];
    }
    while(q--){
        op=read();
        if(op==1){
            ans=-INF;
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
                //st++;en--;
                tmp=INF;
                for(int i=st;i<mi;++i){
                    if(f[i]<tmp){
                        tmp=f[i];
                        st=i;
                    }
                }
                tmp=-INF;
                for(int i=en;i>=mi;--i){
                    if(f[i]>tmp){
                        tmp=f[i];
                        en=i;
                    }
                }
                cout<<"MI"<<mi<<endl;
                for(int i=1;i<=n;++i) cout<<f[i]<<' ';
                cout<<endl;
                cout<<"ST"<<st<<" EN"<<en<<endl;
                ans=max(ans,f[en]-f[st]);
            }
            write(ans);
            putchar('\n');
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