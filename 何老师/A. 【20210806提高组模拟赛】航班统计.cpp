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
void exgcd(int a,int b,int &x,int &y,int &d){
    if(b==0){
        x=1;
        y=0;
        d=a;
        return;
    }
    exgcd(b,a%b,x,y,d);
    int z=x;
    x=y;
    y=z-y*(a/b);
}
signed main()
{
    int n;
    n=read();
    while(n--){
        int a=read(),b=read();
        if(a%2==0&&b%2==0) printf("-1\n");
        else{
            bool flag=0;
            for(int i=1;i<=max(a,b);++i){
                if((b*i+1)%a==0){
                    flag=1;
                    printf("%lld\n",b*i);
                    break;
                }
            }
            if(!flag)
                printf("-1\n");
        }
        
    }
    return 0;
}