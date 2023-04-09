#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
int ans=0;
void gcd(int a,int b){
    if(a==b||b==0) return;
    if(a<b) swap(a,b);
    ans+=a/b;
    gcd(b,a%b);
}
int a,b;
signed main()
{
    a=read();
    b=read();
    if(a==b){
        cout<<"0"<<endl;
        return 0;
    }
    if(a<b) swap(a,b);
    gcd(a,b);
    printf("%lld\n",ans-1);
    return 0;
}