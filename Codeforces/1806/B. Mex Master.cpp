#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
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
int t,n,da;
int a[200005],tong[400005];
int main()
{
    t=read();
    while(t--){
        n=read();
        da=0;
        for(int i=1;i<=n;++i){
            a[i]=read();
            da=max(da,a[i]);
        }
        for(int i=0;i<=da;++i) tong[i]=0;
        for(int i=1;i<=n;++i) ++tong[a[i]];
        if(tong[0]<=(n+1)/2){
            cout<<0<<endl;
        }
        else{
            if(tong[0]==n) cout<<1<<endl;
            else{
                if(tong[0]+tong[1]==n) cout<<2<<endl;
                else cout<<1<<endl;
            }
        }
    }
    return 0;
}