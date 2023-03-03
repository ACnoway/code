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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int mod=1000000007;
int n,m,k,ans;
struct node{
    int x,y;
}a[1003];
bool cmp(node a,node b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
signed main()
{
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=k;++i){
        a[i].x=read();
        a[i].y=read();
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=k;++i){
        ans=(ans+(a[i].x*a[i].y)%mod*((n-a[i].x+1)*(m-a[i].y+1))%mod)%mod;
        for(int j=1;j<i;++j){
            
        }
    }
    return 0;
}