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
inline void write(int x){
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
    
    return 0;
}