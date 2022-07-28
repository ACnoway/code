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
int a,b,c,d;
int main()
{
    a=read();
    b=read();
    c=read();
    d=read();
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    write(min(abs(c-a)+abs(d-b),b-a));
    return 0;
}