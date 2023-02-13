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
int m,d,n,x,t;
int f[21][200005];
char op;
inline int query(int l,int r){
    int x=log2(r-l+1);
    return max(f[x][l],f[x][r-(1<<x)+1]);
}
inline void update(int v){
    n++;
    f[0][n]=v;
    for(int j=1;1<<j<=n;++j){
        //for(int i)
        f[j][n-(1<<j)+1]=max(f[j-1][n-(1<<j)+1],f[j-1][n-(1<<j-1)+1]);
    }
}
signed main()
{
    m=read();d=read();
    while(m--){
        getchar();
        op=getchar();
        x=read();
        if(op=='Q'){
            t=query(n-x+1,n);
            write(t);
            putchar('\n');
        }
        else{
            //n++;
            x=(t+x)%d;
            update(x);
        }
    }
    return 0;
}