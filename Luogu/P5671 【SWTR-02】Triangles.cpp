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
int x,m,n;
int main()
{
    x=read();
    m=read();
    n=read();
    if(x<90)x=180-x;
    cout<<(180-x)/2<<' '<<(x/2)<<endl;
    if(m==n){
        printf("%.5f",sqrt(n*n+m*m));
        return 0;
    }
    else{
        printf("%.5f %.5f",sqrt(abs(n*n-m*m)),sqrt(n*n+m*m));
        return 0;
    }
    return 0;
}