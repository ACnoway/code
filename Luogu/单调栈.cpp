#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
const int maxn=3000006;
int n,top;
int a[maxn],st[maxn],ans[maxn];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=n;i;--i){
        while(top&&a[st[top]]<=a[i]) top--;
        ans[i]=top?st[top]:0;
        st[++top]=i;
    }
    for(int i=1;i<=n;++i) printf("%d ",ans[i]);
    return 0;
}