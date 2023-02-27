#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
#define int long long
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
const int maxn=200005;
int n,c;
int a[maxn],sell[maxn],buy[maxn];
signed main()
{
    n=read();
    c=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=0;i<n;++i){
        buy[i]=read();
        sell[i]=read();
    }
    buy[n]=LONG_LONG_MAX;
    sell[n]=-1;
    int bef=0,now=0,to=0,ma=0,mai=0,mi=0,mii=0,ans=0,lft=0,earn;
    int lzc=0,lzm;
    int ANS=LONG_LONG_MAX,tmp;
    while(now!=n){
        ma=0;
        mai=-1;
        mi=LONG_LONG_MAX;
        mii=-1;
        to=now;
        earn=0;
        while(to+1<=n&&(a[to+1]-a[now])<=c){
            to++;
            debug(to);
            if(sell[to]>ma){
                ma=sell[to];
                mai=to;
            }
            if(buy[to]<mi){
                mi=buy[to];
                mii=to;
            }
            if(buy[to]<buy[now]) break;
        }
        debug(to+1);
        if(to==n){
            tmp=ans;
            if(ma>buy[now]){
                ans+=buy[now]*(c-lzc);
                ans-=ma*(c-a[n]+a[now]);
            }
            else ans+=buy[now]*(a[n]-a[now]-lzc);
            ANS=min(ANS,ans);
            ans=tmp;
        }
        if(buy[to]<buy[now]){
            ans+=(a[to]-a[now]-lzc)*buy[now];
            debug(lzc);
            lzc=0;
            if(ma>buy[now]){
                ans-=(c-a[to]+a[now])*ma;
            }
        }
        else{
            lft=c-a[mii]+a[now];
            if(ma>mi){
                ans=ans+c*buy[now]-ma*lft;
            }
            else{
                ans=ans+c*buy[now];
                lzc=lft;
            }
        }
        now=mii;
        debug(now);
        if(mai==-1&&mii==-1) break;
        debug(ans)
    }
    write(ANS);
    putchar('\n');
    return 0;
}