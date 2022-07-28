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
int n,m,ans,guess;
int a[1005];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            a[j]+=read();
        }
    }
    for(int i=1;i<=n;++i){
        if(a[i]>(m-a[i])) guess=1;
        else guess=0;
        if(guess==read()) ans++;
    }
    write(ans);
    return 0;
}