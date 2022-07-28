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
int n,ans;
int a[20];
int main()
{
    n=read();
    for(int i=0;i<=15;++i) a[i]=2;
    for(int i=1;i<=n;++i){
        int id,s;
        id=read();
        s=read();
        if(a[id]==2){
            a[id]=s;
        }
        else{
            ans+=a[id]!=s;
            a[id]=s;
        }
    }
    write(ans);
    return 0;
}