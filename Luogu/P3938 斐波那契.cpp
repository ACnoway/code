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
int m,a,b;
int fibo[70];
signed main()
{
    fibo[1]=1;
    fibo[0]=1;
    for(int i=2;i<=61;++i) fibo[i]=fibo[i-1]+fibo[i-2];
    m=read();
    int ptr;
    while(m--){
        a=read();
        b=read();
        while(a!=b){
            if(a<b) swap(a,b);
            ptr=lower_bound(fibo+1,fibo+61,a)-fibo;
            a-=fibo[ptr-1];
        }
        printf("%d\n",a);
    }
    return 0;
}