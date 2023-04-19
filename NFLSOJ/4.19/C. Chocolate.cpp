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
struct node{
    int v,w,id;
    bool operator <(const node &x)const{
        return id==x.id?w>x.w:v>x.v;
    }
}a[N],b[N];
bool p[N];
int main()
{
    freopen("chocolate.in","r",stdin);
    freopen("chocolate.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i){
            a[i].v=read(); b[i].v=read();
            a[i].w=b[i].v; b[i].w=a[i].v;
            a[i].id=i; b[i].id=i;
            p[i]=0;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        bool flag=0;
        for(int i=1,j=1;i<=n&&j<=n;){
            if(a[i].id==b[j].id){
                flag=1;
                cout<<"YES"<<endl;
                break;
            }
            p[a[i].id]=1;
            p[b[j].id]=1;
            while(i<n&&a[i].v==a[i+1].v){
                ++i;
                p[a[i].id]=1;
            }
            while(j<n&&b[j].v==b[j+1].v){
                ++j;
                p[b[j].id]=1;
            }
            while(p[a[i].id]) ++i;
            while(p[b[j].id]) ++j;
        }
        if(!flag) cout<<"NO"<<endl;
    }
    return 0;
}