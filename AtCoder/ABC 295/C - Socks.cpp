#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
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
int n,ans,x;
map<int,int> m;
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        x=read();
        m[x]++;
    }
    for(auto i:m){
        ans+=(i.second>>1);
    }
    cout<<ans<<endl;
    return 0;
}