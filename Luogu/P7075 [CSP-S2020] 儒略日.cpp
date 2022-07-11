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
    if(x<0){x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int q,r;
int y,m,d,run;
int main()
{
    q=read();
    while(q--){
        r=read();
        y=-4713;
        m=1;
        d=1;
        run=0;
        while(r){
            if(y<0){
                
            }
            else if(y==0){
                ++y;
                continue;
            }
            else{

            }
        }
    }
    return 0;
}