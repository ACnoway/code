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
int T,n,s;
int w[N],v[N];
int main()
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        s=read();
        for(int i=1;i<=n;++i) w[i]=read();
        for(int i=1;i<=n;++i) v[i]=read();
        int sum=0,cnt=0,ans=0;
        for(int i=0;i<=s;++i){
            sum=cnt=0;
            for(int j=1;j<=n;++j){
                if(i>=cnt+w[j]) sum+=v[j],cnt+=w[j];
            }
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}