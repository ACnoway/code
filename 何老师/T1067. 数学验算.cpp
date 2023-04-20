#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=2003;
int n,m;
int a[N];
bool b[N];
signed main()
{
    n=read(); m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read(),w=read();
        if(b[u]&&a[u]!=w){
            putchar('W');
        }
        else{
            b[u]=1;
            a[u]=w;
            putchar('R');
        }
    }
    return 0;
}