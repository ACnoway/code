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
const int N=1000006;
int n,m,k;
int a[N],tong[N];
int main()
{
    n=read(); k=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        ++tong[a[i]];
        m=max(m,a[i]);
    }
    int cnt=0;
    for(int i=m;i;--i){
        cnt=0;
        for(int j=i;j<=m;j+=i){
            cnt+=tong[j];
        }
        if(cnt>=k){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}