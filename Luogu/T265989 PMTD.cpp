#include<iostream>
#include<cstdio>
using namespace std;
int n,m,x;
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
inline void write(long long x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main()
{
    n=read();
    m=read();
    if(n==1){
        putchar('0');
        return 0;
    }
    int mi=1000000009;
    long long ma=0;
    for(int i=0;i<n;++i) x=read(),mi=min(mi,x),ma=max(ma,(long long)x);
    if(ma<2) ma+=2;
    else ma<<=1;
    m--;
    while(m--) ma<<=1;
    write(ma-mi);
    return 0;
}