//! 被卡空间力
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
const int maxn=1000006;
int n,m;
int a[maxn],f1[21][maxn],f2[21][maxn];
int querymax(int x,int y){
    int z=log2(y-x+1);
    return max(f1[z][x],f1[z][y-(1<<z)+1]);
}
int querymin(int x,int y){
    int z=log2(y-x+1);
    return min(f2[z][x],f2[z][y-(1<<z)+1]);
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i) f1[0][i]=a[i],f2[0][i]=a[i];
    //* j=0推出j=1, j=1推出j=2...
    for(int j=1;j<=20;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            f1[j][i]=max(f1[j-1][i],f1[j-1][i+(1<<j-1)]);
            f2[j][i]=min(f2[j-1][i],f2[j-1][i+(1<<j-1)]);
        }
    }
    int l,r,ma;
    for(int i=m;i<=n;++i){
        l=i-m+1;r=i;
        write(querymin(l,r));
        putchar(' ');
    }
    putchar('\n');
    for(int i=m;i<=n;++i){
        l=i-m+1;r=i;
        write(querymax(l,r));
        putchar(' ');
    }
    putchar('\n');
    return 0;
}