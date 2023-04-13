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
const int N=100005;
int n;
int a[N],qian[N],hou[N];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i){
        qian[i]=max(qian[i-1],0ll)+a[i];
    }
    for(int i=1;i<=n;++i){
        qian[i]=max(qian[i-1],qian[i]);
    }
    for(int i=n;i;--i){
        hou[i]=max(hou[i+1],0ll)+a[i];
    }
    for(int i=n;i;--i){
        hou[i]=max(hou[i+1],hou[i]);
    }
    int ans=qian[1]+hou[2];
    for(int i=2;i<n;++i){
        ans=max(ans,qian[i]+hou[i+1]);
    }
    printf("%lld\n",ans);
    return 0;
}