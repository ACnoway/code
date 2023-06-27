#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int mod=1e9+7;
int T,n,m;
int main()
{
    T=read();
    int ok,all;
    while(T--){
        n=read(); m=read();
        if(m>n){
            printf("0.000000\n");
            continue;
        }
        if(m==0){
            printf("1.000000\n");
            continue;
        }
        printf("%.6lf\n",(double)(n-m+1)/(double)(n+1));
    }
    return 0;
}