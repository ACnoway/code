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
const int maxn=100005;
int n,c;
int a[maxn],sell[maxn],buy[maxn];
int hs,ts,sellq[maxn];
int hb,tb,buyq[maxn];
int tons[maxn],tonb[maxn];
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
    for(int i=n;i>=0;--i){
        while(hs<ts&&a[sellq[hs+1]]-a[i]>c) hs++;
        while(hs<ts&&sell[sellq[ts]]<sell[i]) ts--;
        tons[i]=sellq[hs+1];
        sellq[++ts]=i;
    }
    tonb[n]=n;
    tonb[n-1]=n;
    for(int i=n-2;i>=0;--i){
        while(hb<tb&&a[buyq[hb]]-a[i]>c) hb++;
        while(hb<tb&&buy[buyq[tb]]>buy[i]) tb--;
        tonb[i]=buyq[hb+1];
        buyq[++tb]=i;
        /*if(buy[i+1]<buy[i]) tonb[i]=i+1;
        else tonb[i]=tonb[i+1];*/
    }
    int ans=0,sheng=0,left=0,zou,tosell=0;
    for(int i=0;i<n;i=zou-1){
        debug(i);
        debug(tonb[i]);
        if(buy[tonb[i]]>buy[i]){
            //如果那边贵就梭哈
            ans+=buy[i]*(c-left);
            left=c;
        }
        else{
            //否则等到那边再买
            ans+=buy[i]*(a[tonb[i]]-a[i]-left);
            left=a[tonb[i]]-a[i];
        }
        debug(left);
        for(zou=i+1;zou<=tonb[i];++zou){
            debug(a[zou]);
            left-=a[zou]+a[zou-1];
            if(buy[zou]<buy[i]) break;
            if(zou==tons[i]){
                ans-=sell[zou]*tosell;
                left-=tosell;
                tosell=0;
                if(tonb[i]!=n) ans-=sell[zou]*(left-a[tonb[i]]+a[zou]);
                debug(ans);
                continue;
            }
            if(tons[zou]!=n&&buy[zou]<sell[tons[zou]]){
                tosell+=c-left;
                ans+=buy[zou]*(c-left);
                left=c;
            }
            debug(ans);
        }
    }
    write(ans);
    putchar('\n');
    return 0;
}