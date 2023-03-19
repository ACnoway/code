#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int __int128_t
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int B=1000,K=6;
int t,n,ans,tmp,now,l,r,mid;
bool flag;
signed main()
{
    t=read();
    while(t--){
        n=read();
        ans=0;
        for(int i=2;i<=B;++i){
            tmp=n;
            flag=1;
            while(tmp){
                now=tmp%i;
                tmp/=i;
                if(now>1){
                    flag=0;
                    break;
                }
            }
            ans+=flag;
        }
        for(int i=0;i<(1<<K)-1;++i){
            l=B+1;
            r=n;
            flag=0;
            while(l<=r){
                mid=(l+r)>>1;
                now=0;
                for(int j=0;j<K;++j){
                    now=now*mid+((i>>j)&1);
                    if(now>n) break;//防止溢出
                }
                if(now==n){
                    flag=(mid>B);
                    break;
                }
                if(now>n) r=mid-1;
                else l=mid+1;
            }
            ans+=flag;
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}