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
int t,n,r,b;
int main()
{
    t=read();
    while(t--){
        n=read();
        r=read();
        b=read()+1;
        int zheng=r/b,yu=r%b;
        for(int i=1;i<=yu;++i){
            for(int j=0;j<=zheng;++j) putchar('R');
            putchar('B');
        }
        for(int i=1;i<=b-yu;++i){
            for(int j=1;j<=zheng;++j) putchar('R');
            if(i<b-yu) putchar('B');
        }
        putchar('\n');
    }
    return 0;
}