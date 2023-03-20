#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=500005;
int n,m,k,x,y,tmp,lcm,g;
int p[N<<1];
vector<int> a;
int exgcd(int a,int b,int &x,int &y){
    int xx=0,yy=1,tmp;
    x=1;y=0;
    while(b){
        tmp=xx;
        xx=x-a/b*xx;
        x=tmp;
        tmp=yy;
        yy=y-a/b*yy;
        y=tmp;
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
signed main()
{
    n=read();
    m=read();
    k=read();
    g=exgcd(n,m,x,y);
    lcm=n*m/g;
    x=(x+m)%m;
    for(int i=1;i<=n;++i){
        tmp=read();
        p[tmp]=i;
    }
    for(int i=1;i<=m;++i){
        tmp=read();
        if(p[tmp]&&!((i-p[tmp])%g)){
            a.push_back(((x*(i-p[tmp])/g*n+p[tmp]-1)%lcm+lcm)%lcm+1);
        }
    }
    int d=lcm-a.size(),f=(k-1)/d,mf=(k-1)%d+1;
    int pos=a.size()+1;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();++i){
        if(mf<=a[i]-i-1){
            pos=i+1;
            break;
        }
    }
    printf("%lld\n",f*lcm+mf+pos-1);
    return 0;
}