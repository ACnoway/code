#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
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
inline void write(__int128_t x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,m,c,k;
int can[70],buy[70];
signed main()
{
    n=read();
    m=read();
    c=read();
    k=read();
    int temp=0,cnt=0;
    for(int i=0;i<n;++i){
        temp=read();
        cnt=0;
        while(temp){
            buy[cnt]=buy[cnt]||(temp-((temp>>1)<<1));
            temp>>=1;
            cnt++;
        }
    }
    int p,q;
    for(int i=0;i<m;++i){
        p=read();
        q=read();
        if(!buy[p]) can[p]=2;
    }
    __int128_t ans=1;
    for(int i=1;i<=k;++i){
        ans<<=1;
    }
    for(int i=0;i<=k;++i){
        if(can[i]==2) ans/=2.0;
    }
    write(ans-n);
    putchar('\n');
    return 0;
}