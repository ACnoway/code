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
int n,top,ans;
int a[maxn],st[maxn],cnt[maxn];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=n;i;--i){
        while(top&&a[st[top]]<=a[i]){
            ans+=cnt[top];
            if(a[i]!=a[st[top]]) cnt[top]=0;
            top--;
        }
        st[++top]=i;
        cnt[top]++;
        if(top-1) ans++;
    }
    write(ans);
    putchar('\n');
    return 0;
}