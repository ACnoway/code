#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
const int maxn=500005;
int n,k,now,ans,ma;
int a[maxn],t[maxn];
signed main()
{
    n=read();
    k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int l=1;l<=n;++l){
        for(int r=n;r>=l;--r){
            if(r-l+1>=k){
                ma=0;
                for(int i=l;i<=r;++i) ma=max(ma,a[i]);
                now=0;
                for(int i=l;i<=r;++i){
                    if(a[i]<=(ma-k+1)) now=max(now,a[i]);
                }
                ans+=now;
                ma=0;
            }
        }
    }
    write(ans);
    putchar('\n');
    return 0;
}