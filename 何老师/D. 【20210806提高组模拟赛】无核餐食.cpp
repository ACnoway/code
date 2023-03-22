#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
const int N=300005;
int n,k,q;
int dp[N<<2],p[N<<2];
bool vis[N<<2];
/*struct node{
    int price[5];
    int top;
    node(){top=0;}
    bool operator <(const node &x)const{
        for(int i=1;i<=k;++i){
            if(price[i]!=x.price[i]) return price[i]<x.price[i];
        }
        return 0;
    }
}a[N];*/
struct food{
    int qian,id;
    bool operator <(const food &x)const{
        if(qian==x.qian) return id<x.id;
        return qian<x.qian;
    }
}a[N<<4];
int f[N][5];
signed main()
{
    n=read(); k=read(); q=read();
    for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j){
            a[i+j*n].qian=read();
            a[i+j*n].id=i+j*n;
            //f[i][j]=f[i][j-1]+a[i].qian;
        }
    }
    sort(a+1,a+n*k+1);
    for(int i=1;i<=n*k;++i) p[a[i].id]=i;
    int now=1;
    //vis的下标是排序后的
    for(int i=1;i<=n*k;++i){
        while(vis[now]) ++now;
        for(int j=now;j<=n*k;++j){
            if(vis[j]) continue;
            if(a[j].id>n){
                //如果他之前的没被买就不能被买
                if(!vis[p[a[j].id-n]]) continue;
                dp[i]=dp[i-1]+a[j].qian;
                vis[j]=1;
                break;
            }
            else{
                dp[i]=dp[i-1]+a[j].qian;
                vis[j]=1;
                break;
            }
        }
    }
    while(q--){
        int c=read();
        printf("%lld\n",dp[c]);
    }
    return 0;
}