#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=100005;
int n,m;
int a[maxn],f[maxn][21];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) f[i][0]=a[i];
    //* j=0推出j=1, j=1推出j=2...
    for(int j=1;j<=20;++j){
        for(int i=1;i+(1<<j)<n;++i){
            f[i][j]
        }
    }
    int l,r,ma;
    while(m--){
        cin>>l>>r;
        ma=0;
        for(int i=l;i<=r;++i) ma=max(ma,a[i]);
        cout<<ma<<endl;
    }
    return 0;
}