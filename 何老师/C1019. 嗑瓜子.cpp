#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
const int p=998244353,maxn=2003;
int n;
int inv[100005];
int f[maxn][maxn<<1];
void init(){
    inv[1]=1;
    for(int i=2;i<=(n<<2);++i){
        inv[i]=(p-(p/i))*inv[p%i]%p;
    }
}
signed main()
{
    n=read();
    init();
    for(int i=1;i<=n;++i){
        for(int j=0;j<=((n-i)*2);++j){
            f[i][j]=(f[i-1][j+2]*inv[i+j]%p*(i)%p+1ll)%p;
            debug(f[i][j]);
            if(j>=1) f[i][j]=(f[i][j]+f[i][j-1]*inv[i+j]%p*(j)%p)%p;
        }
    }
    write(f[n][0]);
    return 0;
}