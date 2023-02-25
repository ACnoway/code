#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int maxn=100005;
int n,k;
int a[maxn];
int main()
{
    n=read();
    k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+n+1);
    int ans=1;
    for(int i=1;i<n;++i){
        if(a[i+1]-a[i]>k) ans=1;
        else ans++;
    }
    write(ans);
    putchar('\n');
    return 0;
}