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
int n,x=1000000009,ans;
int a[100005];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        x=min(x,a[i]-i);
    }
    for(int i=1;i<=n;++i){
        ans+=abs(a[i]-(x+i));
    }
    cout<<ans<<endl;
    return 0;
}