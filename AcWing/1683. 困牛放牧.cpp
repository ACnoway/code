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
int main()
{
    int a=read(),b=read(),c=read(),ans=0;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>c) swap(a,c);
    if(a+1==b&&b+1==c){
        cout<<"0\n0"<<endl;
        return 0;
    }
    if(c-b==2||b-a==2) write(1);
    else write(2);
    putchar('\n');
    write(max(c-b-1,b-a-1));
    return 0;
}