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
int n,k,q;
signed main()
{
    n=read(); k=read();
    q=read();
    while(q--){
        int x=read(),y=read(),ans=0;
        while(x!=y){
            if(x<y) swap(x,y);
            ans++;
            x=(x+k-2)/k;
        }
        printf("%lld\n",ans);
    }
    return 0;
}