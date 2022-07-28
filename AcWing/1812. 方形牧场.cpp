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
int a[2]={20,20},b[2];
int main()
{
    a[0]=min(a[0],read());
    a[1]=min(a[1],read());
    b[0]=max(b[0],read());
    b[1]=max(b[1],read());
    a[0]=min(a[0],read());
    a[1]=min(a[1],read());
    b[0]=max(b[0],read());
    b[1]=max(b[1],read());
    write(pow(max(b[0]-a[0],b[1]-a[1]),2));
    putchar('\n');
    return 0;
}