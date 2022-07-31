#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
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
void write(ll x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
ll ans;
bool vis[10000007];
int main()
{
    int n;
    n=read();
    for(int i=0;i<n;++i){
        int x,t;
        x=read();
        t=read();
        if(!vis[x]&&t>1){
            vis[x]=1;
            ans+=t;
        }
    }
    write(ans);
    return 0;
}