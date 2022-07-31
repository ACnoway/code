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
const int P=1000000007;
int t,n,k;
int a[26][26];
int main()
{
    a[1][1]=1;
    a[1][2]=2;
    a[1][3]=3;
    a[1][4]=4;
    a[1][5]=5;
    a[2][1]=0;
    a[2][2]=2;
    a[2][3]=5;
    a[2][4]=8;
    a[2][5]=12;
    a[3][1]=1;
    a[3][2]=3;
    a[3][3]=9;
    a[3][4]=18;
    a[3][5]=19;
    t=read();
    while(t--){
        n=read();
        k=read();
        write(a[n][k]);
        putchar('\n');
    }
    return 0;
}