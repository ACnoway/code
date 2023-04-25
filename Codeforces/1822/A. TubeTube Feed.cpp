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
int T,n,t,ans;
int a[100],b[100];
int main()
{
    T=read();
    while(T--){
        n=read(); t=read();
        ans=0;int mp=0;
        int ed;
        for(int i=0;i<n;++i){
            a[i]=read();
        }
        for(int i=0;i<n;++i){
            b[i]=read();
            if(a[i]+i<=t&&b[i]>ans) ans=b[i],mp=i+1;
        }
        cout<<(mp?mp:-1)<<endl;
    }
    return 0;
}