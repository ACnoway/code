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
int n,a,b;
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        char c=getchar();
        while(c!='0'&&c!='1') c=getchar();
        a+=c-'0';
    }
    for(int i=1;i<=n;++i){
        char c=getchar();
        while(c!='0'&&c!='1') c=getchar();
        b+=c-'0';
    }
    write(abs(a-b));
    putchar('\n');
    return 0;
}