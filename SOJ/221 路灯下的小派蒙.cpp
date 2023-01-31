#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,q,l,r,la,ra,ans;
int a[100005];
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
int main()
{
    n=read();q=read();
    for(int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+n+1);
    while(q--){
        l=read();r=read();
        la=lower_bound(a+1,a+n+1,l)-a;
        ra=upper_bound(a+1,a+n+1,r)-a;
        write(ra-la);
        putchar('\n');
    }
    return 0;
}