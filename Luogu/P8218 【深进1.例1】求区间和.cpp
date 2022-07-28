#include <iostream>
#include <cstdio>
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
int n,m;
int a[100005];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read(),a[i]+=a[i-1];
    m=read();
    int x,y;
    for(int i=1;i<=m;++i){
        x=read();
        y=read();
        write(a[y]-a[x-1]);
        putchar('\n');
    }
    return 0;
}