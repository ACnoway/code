#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
#define int long long
using namespace std;
int t,n,x,ac,bc,ans;
int a[65],b[65],c[65];
bool flag=1;
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
        n=read();x=read();
        debug(n);debug(x);
        ans=0;
        ac=bc=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        if(x>n) write(-1);
        else if(x==n) write(n);
        else if(x==0){
            //转二进制
            while(n){
                a[ac++]=n&1;
                n>>=1;
            }
            debug(ac);
            write(1ull<<ac);
        }
        else{
            //转二进制
            while(n){
                a[ac++]=n&1;
                n>>=1;
            }
            while(x){
                b[bc++]=x&1;
                x>>=1;
            }
            //长度不同
            if(ac!=bc){
                write(-1);
                putchar('\n');
                continue;
            }
            int i;
            for(i=0;i<bc;++i){
                if(b[i]) break;
            }
            if(a[i-1]){
                write(-1);
                putchar('\n');
                continue;
            }
            flag=1;
            for(int j=i;j<bc;++j){
                if(a[j]!=b[j]){
                    flag=0;
                    break;
                }
                c[j]=a[j];
            }
            if(!flag){
                write(-1);
                putchar('\n');
                continue;
            }
            flag=0;
            for(i=i-2;i>=0;--i){
                if(a[i]) break;
            }
            c[i+1]=1;
            for(i=0;i<bc;++i){
                ans+=(c[i]<<i);
            }
            write(ans);
        }
        putchar('\n');
    }
    return 0;
}