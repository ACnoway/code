#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int n;
double a[1003];
int main()
{
    n=read();
    for(int i=1;i<=5*n;++i) a[i]=read();
    sort(a+1,a+1+5*n);
    double ans=0;
    for(int i=n+1;i<=4*n;++i) ans+=a[i];
    printf("%.15lf\n",(double)(ans)/(3*n));
    return 0;
}