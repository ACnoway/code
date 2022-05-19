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
inline void write(long long x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline long long minn(long long a,long long b){
    return a<b?a:b;
}
int n,a,b,c;
int main()
{
    n=read();
    a=read();b=read();c=read();
    long long ans=n+n-1,ans1=ans;
    if(c>=n){
        ans1=ans1+b-a+1;
        ans=ans+c-n+2+c-n;
    }
    write(minn(ans1,ans));
    return 0;
}