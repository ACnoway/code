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
int t,n;
int a[600];
int main()
{
    t=read();
    while(t--){
        n=read();
        int s=0,e=0,l=0;
        for(int i=0;i<550;++i) a[i]=0;
        for(int i=1;i<=n;++i){
            cout<<"? 1 "<<i
        }
    }
    return 0;
}