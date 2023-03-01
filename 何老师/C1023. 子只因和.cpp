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
int n,m,top;
int a[60],b[10004],dp[10004];
signed main()
{
    n=read();
    m=read();
    for(int i=0;i<=m;++i) b[i]=read();
    dp[0]=1;
    for(int i=1;i<=m;++i){
        while(b[i]>dp[i]){
            for(int j=m;j>=i;--j){
                dp[j]+=dp[j-i];
            }
            a[++top]=i;
        }
    }
    for(int i=1;i<=top;++i) write(a[i]),putchar(' ');
    putchar('\n');
    return 0;
}