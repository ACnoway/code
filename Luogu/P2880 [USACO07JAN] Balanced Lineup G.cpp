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
const int maxn=180005;
int n,m,l,r;
int a[maxn],fa[21][maxn],fi[21][maxn];
inline int queryma(int x,int y){
    int z=log2(y-x+1);
    return max(fa[z][x],fa[z][y-(1<<z)+1]);
}
inline int querymi(int x,int y){
    int z=log2(y-x+1);
    return min(fi[z][x],fi[z][y-(1<<z)+1]);
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i) fa[0][i]=fi[0][i]=a[i];
    for(int j=1;1<<j<=n;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            fa[j][i]=max(fa[j-1][i],fa[j-1][i+(1<<(j-1))]);
            fi[j][i]=min(fi[j-1][i],fi[j-1][i+(1<<(j-1))]);
        }
    }
    while(m--){
        l=read();r=read();
        write(queryma(l,r)-querymi(l,r));
        putchar('\n');
    }
    return 0;
}