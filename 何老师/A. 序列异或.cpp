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
const int maxn=5003;
int n,ans;
int a[maxn],cnt[3000006];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int k=1;k<=n;++k){
        for(int i=k+1;i<=n;++i) ans+=cnt[a[i]^a[k]];
        for(int i=1;i<k;++i){
            cnt[a[i]^a[k]]++;
        }
    }
    write(ans);
    putchar('\n');
    return 0;
}