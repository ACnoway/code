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
const int N=300005,inf=1;
int t,n;
int a[N];
signed main()
{
    t=read();
    a[0]=-214748364700;
    while(t--){
        n=read();
        for(int i=1;i<=n;++i){
            a[i]=read();
        }
        int ls=0;
        for(int i=1;i<n;++i){
            a[i]-=ls;
            ls=a[i]-a[i-1]-1;
            a[i]=a[i-1]+1;
        }
        a[n]-=ls;
        if(a[n]<a[n-1]) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}