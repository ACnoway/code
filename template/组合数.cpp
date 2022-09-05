#include<bits/stdc++.h>
#define int __int128_t
using namespace std;
int n,m;
int read(){
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
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int work(){
    int ans=1;
    for(int i=m;i<=n;++i) ans*=i;
    for(int i=1;i<=m;++i) ans/=i;
    return ans;
}
signed main()
{
    n=read();
    m=read();
    write(work());
    return 0;
}