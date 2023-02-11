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
int n,m,x;
int a[102];
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;++i) x=read(),a[x]=x+1;
    int st=1;
    for(int i=1;i<=n;i=st+1){
        st=i;
        while(a[st]) st=a[st];
        for(int j=st;j>=i;--j) write(j),putchar(' ');
    }
    return 0;
}