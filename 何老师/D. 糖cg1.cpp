#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
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
inline void write(ll x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=200005;
struct Candy{
    int val,cnt;
}t[maxn];
int n,c,l,r,cnt;
ll ans;
int a[maxn],sell[maxn],buy[maxn];
inline void maichu(int x){
    //找到买入价格比x价格低的，以x的价格卖出
    int sum=0;
    while(l<=r&&x>t[l].val){
        sum+=t[l++].cnt;
    }
    if(sum){
        //记录卖出价格和个数
        t[--l].val=x;
        t[l].cnt=sum;
    }
}
inline void mairu(int x){
    while(l<=r&&x<t[r].val){
        ans-=1ll*t[r].cnt*t[r].val;
        cnt+=t[r--].cnt;
    }
}
inline void yong(int x){
    while(x&&l<=r){
        int need=min(x,t[l].cnt);
        x-=need;
        t[l].cnt-=need;
        if(t[l].cnt==0) l++;
    }
}
int main()
{
    n=read();
    c=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    for(int i=0;i<n;++i){
        buy[i]=read();
        sell[i]=read();
    }
    for(int i=0;i<n;++i){
        maichu(sell[i]);
        cnt=(i?a[i]-a[i-1]:c);
        mairu(buy[i]);
        t[++r].val=buy[i];
        t[r].cnt=cnt;
        ans+=1ll*cnt*buy[i];
        yong(a[i+1]-a[i]);
    }
    maichu(sell[n-1]);
    for(int i=l;i<=r;++i){
        ans-=1ll*t[i].val*t[i].cnt;
    }
    write(ans);
    putchar('\n');
    return 0;
}