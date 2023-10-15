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
int n;
long long a[1000006];
int main()
{
    freopen("min.in","r",stdin);
    freopen("min.out","w",stdout);
    n=read();
    a[0]=0;
    for(int i=1;i<=n;++i){
        a[i]=read();
        a[i]+=a[i-1];
    }
    int tmp,siz=1;
    long long ans=1ll<<61;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            tmp=abs(a[j]-a[i-1]);
            if(tmp<ans){
                siz=j-i+1;
                ans=tmp;
            }
            else if(tmp==ans) siz=max(siz,j-i+1);
        }
    }
    printf("%lld\n%d\n",ans,siz);
    return 0;
}