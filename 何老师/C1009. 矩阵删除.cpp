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
<<<<<<< HEAD
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
=======
>>>>>>> 42b360d230f0abca59c934664b32c286ad4837db
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=3003;
<<<<<<< HEAD
int n,m,k;
char s[maxn][maxn];
int a[maxn][maxn],f[maxn][maxn],g[maxn][maxn];
int main()
{
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=n;++i){
        cin>>s[i]+1;
        for(int j=1;j<=m;++j) a[i][j]=s[i][j]-'0';
    }
    for(int i=1;i<=m;++i){
        f[1][i]=1;
        
=======
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
>>>>>>> 42b360d230f0abca59c934664b32c286ad4837db
    }
    return 0;
}