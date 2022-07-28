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
int a[2][5];
inline int get(int a,int b,int c,int d){
    return max(0,min(b,d)-max(a,c));
}
int main()
{
    for(int i=0;i<2;++i){
        for(int j=0;j<4;++j){
            a[i][j]=read();
        }
    }
    int shu=get(a[0][1],a[0][3],a[1][1],a[1][3]),heng=get(a[0][0],a[0][2],a[1][0],a[1][2]);
    if(shu>=a[0][3]-a[0][1]&&(a[1][2]>a[0][0]&&a[1][0]<=a[0][0]||a[1][2]>=a[0][2]&&a[1][0]<a[0][2])){
        write((a[0][3]-a[0][1])*(a[0][2]-a[0][0]-heng));
    }
    else if(heng>=a[0][2]-a[0][0]&&(a[1][3]>a[0][1]&&a[1][1]<=a[0][1]||a[1][3]>=a[0][3]&&a[1][1]<a[0][3])){
        write((a[0][2]-a[0][0])*(a[0][3]-a[0][1]-shu));
    }
    else{
        write((a[0][2]-a[0][0])*(a[0][3]-a[0][1]));
    }
    return 0;
}