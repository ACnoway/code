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
int t,n,x,same;
int main()
{
    t=read();
    while(t--){
        n=read();
        same=0;
        for(int i=1;i<=n;++i){
            x=read();
            if(x<=0) same++;
        }
        for(int i=1;i<=n-same;++i){
            printf("%d ",i);
        }
        for(int i=1;i<=same;++i){
            printf("%d ",n-same-i);
        }
        putchar('\n');
        for(int i=1;i<=same;++i){
            printf("1 0 ");
        }
        for(int i=1;i<=n-(same<<1);++i){
            printf("%d ",i);
        }
        putchar('\n');
    }
    return 0;
}