#include <iostream>
#include <cstdio>
#include <cmath>
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
struct node
{
    int op,x,y;
}o[300];
int n,m;
int a[1003],b[1003];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=m;++i){
        o[i].op=read();
        o[i].x=read();
        o[i].y=read();
    }
    for(int i=m;i>0;--i){
        if(o[i].op==1){
            if(o[i].x==o[i].y) a[o[i].x]/=2;
            else a[o[i].x]-=a[o[i].y];
        }
        else{
            if(o[i].x==o[i].y) a[o[i].x]=sqrt(a[o[i].x]);
            else a[o[i].x]/=a[o[i].y];
        }
    }
    for(int i=1;i<=n;++i) write(a[i]),putchar(' ');

    return 0;
}