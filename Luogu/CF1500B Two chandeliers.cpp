#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
int n,m,k,mod,ans;
int a[N],b[N],tong[N<<1];
vector<int> t;
void exgcd(int a,int b,int &x,int &y){
    int xx=0,yy=1,tmp;
    x=1,y=0;
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
}
int calc(int x,int y){
    int d=x-y;
    //如果不整除的话直接无解
    if(d%__gcd(n,m)) return -1;
    d=__gcd(n,m);
    int p1=n/d,p2=m/d;
    int r1,r2;
    exgcd(p1,p2,r1,r2);
    int z=x+(y-x)*r1*n/d;
    return x;
}
int main()
{
    n=read(); m=read(); k=read();
    for(int i=1;i<=n;++i) a[i]=read(),tong[a[i]]=i;
    for(int i=1;i<=m;++i) b[i]=read();
    mod=n*m;
    for(int i=1;i<=m;++i){
        //没有跟这个值相同的就跳过
        if(!tong[b[i]]) continue;
        int cnt=calc(tong[b[i]]-1,i-1)+1;
        if(!cnt) continue;
        cnt%=mod;
        if(cnt=0) cnt+=mod;
        t.push_back(cnt);
    }
    sort(t.begin(),t.end());
    int now=mod-t.size();
    while(k>=mod){
        ans+=k-k%mod;
        k-=k/mod*now;
    }
    cout<<ans<<endl;
    return 0;
}