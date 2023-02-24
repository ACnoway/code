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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=3003;
const int mod=1000000007;
int n,m,k;
char s[maxn][maxn];
int f[maxn][maxn],g[maxn][maxn];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) cin>>s[i]+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            
        }
    }
    return 0;
}