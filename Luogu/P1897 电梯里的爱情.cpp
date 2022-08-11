#include<iostream>
#include<cstdio>
using namespace std;
int n,ans,ma;
bool v[20000007];
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
    n=read();
    int x;
    for(int i=0;i<n;++i){
        x=read();
        ma=max(ma,x);
        if(!v[x]){
            v[x]=1;
            ans+=5;
        }
    }
    write(ans+(ma<<3)+(ma<<1)+n);
    return 0;
}