#include<bits/stdc++.h>
using namespace std;
int read(){
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
const int N=400005;
int n;
typedef long long ll;
struct node{
    int x,y;
    double xx,yy;
    bool operator <(const node &a)const{
        return (ll)xx*yy<(ll)a.xx*a.yy;
    }
}a[N];
mt19937_64 orz(time(0) ^ clock());
const ll r = 17364431886729300053LL; //orz();
const double cosr = cos(r), sinr = sin (r);
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i].x=read(),a[i].y=read();
        a[i].xx=a[i].x*sinr-a[i].y*cosr;
        a[i].yy=a[i].x*sinr+a[i].y*cosr;
    }
    sort(a+1,a+n+1);
    long long ans=1e18;
    for(int i=1;i<=n;++i){
        for(int j=1;i-j>0,j<=50;++j){
            ans=min(ans,(ll)(a[i].x-a[i-j].x)*(ll)(a[i].x-a[i-j].x)+(ll)(a[i].y-a[i-j].y)*(ll)(a[i].y-a[i-j].y));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
