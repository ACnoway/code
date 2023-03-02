#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
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
int n,ans;
int a[maxn],b[maxn],to[maxn];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i) b[i]=read();
    for(int i=1;i<=n;++i){
        if(b[i]<a[i]) to[i]=b[i]+4-a[i];
        else to[i]=b[i]-a[i];
    }
    for(int i=1;i<=n;++i){
        if(to[i]>to[i-1]){
            if(i>=3&&to[i]==to[i-2]&&to[i]-2>=to[i-1]) continue;
            ans+=to[i]-to[i-1];
        }
        //debug(ans);
    }
    write(ans);
    putchar('\n');
    return 0;
}