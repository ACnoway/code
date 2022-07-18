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
int a[3][4];
int res=0;
inline int get(int a,int b,int c,int d){
    return max(0,min(b,d)-max(a,c));
}
inline int area(int a[]){
    return (a[2]-a[0])*(a[3]-a[1]);
}
int main()
{
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            a[i][j]=read();
        }
    }
    for(int i=0;i<2;++i)
        res+=get(a[i][0],a[i][2],a[2][0],a[2][2])*get(a[i][1],a[i][3],a[2][1],a[2][3]);
    write(area(a[0])+area(a[1])-res);
    return 0;
}