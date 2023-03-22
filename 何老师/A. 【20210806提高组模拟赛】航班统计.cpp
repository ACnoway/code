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
void exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    int z=x;
    x=y;
    y=z-y*(a/b);
}
signed main()
{
    int n;
    n=read();
    while(n--){
        int a=read(),b=read(),x,y;
        exgcd(a,b,x,y);
        if(a*x+b*y!=1){
            printf("-1\n");
            continue;
        }
        y=-y;
        int t1=b/__gcd(a,b),t2=a/__gcd(a,b);
        y=(y%t2+t2)%t2;
        if(!y) y=t2;
        if((y*b+1)/a<=0) printf("-1\n");
        else printf("%lld\n",y*b);
    }
    return 0;
}