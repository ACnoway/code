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
int t,n,m,x,cnt;
int a[500004],ans[500004];
int main()
{
    t=read();
    while(t--){
        n=read();
        m=read();
        cnt=0;
        for(int i=0;i<=n+m;++i) ans[i]=-1,a[i]=0;
        for(int i=1;i<=m;++i){
            x=read();
            a[x]++;
            if(a[x]==1){
                if(n>=cnt) ans[n-cnt]=i;
                cnt++;
            }
        }
        for(int i=1;i<=n;++i) write(ans[i]),putchar(' ');
        putchar('\n');
    }
    return 0;
}