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
int n,m,a;
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a=read();
            if(a==0){
                putchar('.');
            }
            else putchar(a+'A'-1);
        }
        putchar('\n');
    }
    return 0;
}