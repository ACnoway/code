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
int l,n,m;
struct node{
    int v,cnt;
}a[100005],b[100005];
signed main()
{
    l=read();
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        a[i].v=read();
        a[i].cnt=read();
    }
    for(int i=1;i<=m;++i){
        b[i].v=read();
        b[i].cnt=read();
    }
    int ans=0,i=1,j=1;
    while(i<=n&&j<=m){
        if(a[i].cnt<b[j].cnt){
            if(a[i].v==b[j].v){
                ans+=a[i].cnt;
            }
            b[j].cnt-=a[i].cnt;
            ++i;
        }
        else{
            if(a[i].v==b[j].v){
                ans+=b[j].cnt;
            }
            a[i].cnt-=b[j].cnt;
            ++j;
        }
    }
    printf("%lld\n",ans);
    return 0;
}