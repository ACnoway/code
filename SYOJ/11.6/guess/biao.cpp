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

signed main()
{
    freopen("biao.txt","w",stdout);
    for(int i=1;i<=5000000;++i){
        int x=i,cnt=0;
        while(x!=1){
            if(x&1) x=x*3+1;
            else x>>=1;
            ++cnt;
        }
        printf("%lld,",cnt);
    }
    return 0;
}