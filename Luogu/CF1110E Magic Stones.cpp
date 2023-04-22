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
const int N=100005;
int T,n;
int a[N],b[N],fa[N],fb[N];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i) b[i]=read();
    if(a[1]!=b[1]||a[n]!=b[n]){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1;i<n;++i) fa[i]=a[i+1]-a[i];
    for(int i=1;i<n;++i) fb[i]=b[i+1]-b[i];
    sort(fa+1,fa+n);
    sort(fb+1,fb+n);
    bool flag=1;
    for(int i=1;i<n;++i){
        if(fa[i]!=fb[i]){
            flag=0;
            break;
        }
    }
    if(!flag) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}