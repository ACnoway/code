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
int x,y,ans;
int a[32];
int main()
{
    x=read();
    y=read();
    for(int i=0;i<32;++i) a[i]=(1<<i)*((i&1)?(-1):1);
    int now=x,t=0;
    if(x<y){
        while(now<y){
            now=x+a[t];
            ans+=abs(a[t-1])+abs(a[t++]);
        }
    }
    else{
        while(now>y){
            now=x+a[t];
            ans+=abs(a[t-1])+abs(a[t++]);
        }
    }
    write(ans-abs(now-y));
    return 0;
}