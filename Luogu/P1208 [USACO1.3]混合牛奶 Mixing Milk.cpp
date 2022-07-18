#include <iostream>
#include <cstdio>
#include <algorithm>
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
int n,m,ans;
struct fm{
    int p,a;
    bool operator <(fm x)const{
        return p<x.p;
    }
}b[5003];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i) b[i].p=read(),b[i].a=read();
    sort(b+1,b+m+1);
    for(int i=1;i<=m;++i){
        if(n>=b[i].a){
            ans+=b[i].a*b[i].p;
            n-=b[i].a;
        }
        else{
            ans+=b[i].p*n;
            break;
        }
    }
    write(ans);
    putchar('\n')
    return 0;
}