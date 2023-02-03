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
int t,n,b,cnt,temp,zero,p,ans;
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
        n=read();
        b=read();
        temp=n;
        cnt=0;
        zero=0;
        p=0;
        ans=0;
        while(temp){
            cnt++;
            debug(cnt)
            if(!(temp&1ll)){
                zero++;
                debug(zero);
                p=cnt;
            }
            debug(temp);
            temp>>=1ll;
        }
        ans+=(cnt*(cnt-1)>>1ll);
        ans+=cnt-p-1;
        if(zero==1) ans++;
        write(ans);
        putchar('\n');
    }
    return 0;
}
// 1111101000