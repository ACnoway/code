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
const int maxn=500005;
int n,k;
int a[maxn],p[maxn];
int main()
{
    n=read();
    k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int l,r,cnt=0;
    for(int i=1;i<=n;++i){
        cnt=0;
        for(r=1;cnt<k&&i+r<=n;++r){
            if(a[i+r]>a[i]) cnt++;
        }
        r=i+r-1;
        cnt=0;
        for(l=1;cnt<k&&i-l>0;++l){
            if(a[i-l]>a[i]) cnt++;
        }
        l=i-l+1;
    }
    return 0;
}