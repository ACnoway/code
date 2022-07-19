#include <iostream>
#include <cstdio>
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
    putchar(x%10);
}
const int N=500005;
const int P=1000000007;
int n;
int a[N],b[N],fa[N],fb[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=1;i<=n;++i){
        fa[i]=(a[i]+fa[i-1])%P;
        fb[i]=(b[i]+fb[i-1])%P;
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            ans+=((fa[j]-fa[i-1])*(fb[j]-fb[j-1]))%P;
        }
    }
    cout<<ans<<endl;
    return 0;
}