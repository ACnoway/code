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
const int N=5e6+10,mod=998244353;
int T,n;
long long ans;
bool flag;
long long a[N];
int main()
{
    T=read();
    while(T--){
        ans=0;
        n=read();
        for(int i=1;i<=n;++i){
            a[i]=i;
        }
        do{
            flag=1;
            for(int i=1;i<=n;++i){
                if(a[i]==i){
                    flag=0;
                    break;
                }
            }
            ans+=flag;
            ans%=mod;
        }while(next_permutation(a+1,a+n+1));
        printf("%lld\n",ans);
    }
    return 0;
}