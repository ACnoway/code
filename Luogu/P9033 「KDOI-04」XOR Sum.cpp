#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int t,n,k,m,ck,cm,ans,tmp;
bool kk[40],mm[40],flag;
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
signed main()
{
    t=read();
    while(t--){
        n=read();k=read();m=read();
        if(k>m){
            if(k!=m&&n==1){
                write(-1);
                putchar('\n');
                continue;
            }
            ck=cm=0;
            while(k){
                kk[ck++]=k&1;
                k>>=1;
            }
            tmp=m;
            while(m){
                mm[cm++]=m&1;
                m>>=1;
            }
            if(ck>cm){
                write(-1);
                putchar('\n');
                continue;
            }
            for(int i=ck;i<cm;++i) kk[i]=0;
            /*flag=1;
            for(int i=cm-1;i>=0;--i){
                if(kk[i]&&!mm[i]){
                    flag=0;
                    break;
                }
            }
            if(!flag){
                write(-1);
                putchar('\n');
                continue;
            }*/
            ans=0;
            for(int i=0;i<cm;++i){
                ans+=(1<<i)*(kk[i]^mm[i]);
            }
            write(tmp);putchar(' ');
            write(ans);
            for(int i=2;i<n;++i){
                putchar(' ');
                putchar('0');
            }
        }
        else{
            write(k);
            for(int i=1;i<n;++i){
                putchar(' ');
                putchar('0');
            }
        }
        putchar('\n');
    }
    return 0;
}