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
int t,n;
int a[102];
inline int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main()
{
    t=read();
    bool flag;
    while(t--){
        n=read();
        flag=0;
        for(int i=1;i<=n;++i){
            a[i]=read();
            if(!flag);
            for(int j=1;j<i;++j){
                if(gcd(a[i],a[j])<=2){
                    flag=1;
                    break;
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}