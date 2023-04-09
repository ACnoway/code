#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
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
const int N=20;
int n,k;
int a[N],t[N];
set<int> s;
signed main()
{
    n=read();
    k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int now=0;
    for(int i=1;i<=k;++i){
        if(s.size()){
            now=*s.begin();
            s.erase(now);
        }
        // cout<<now<<endl;
        for(int j=1;j<=n;++j){
            s.insert(now+a[j]);
        }
    }
    printf("%lld\n",*s.begin());
    return 0;
}