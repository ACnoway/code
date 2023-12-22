#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
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
const int N=1600;
int n,m,k;
int a[N][N],f[N][N];
typedef pair<int,int> pii;
pii c[N];
struct node{
    int sum,xa,ya,xb,yb;
    bool operator <(const node &x)const{
        if(sum==x.sum){
            if(xa==x.xa) return ya<x.ya;
            return xa<x.xa;
        }
        return sum>x.sum;
    }
};
vector<node> b;
int main()
{
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i][j]=read();
            f[i][j]=a[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    for(int i=1;i+k-1<=n;++i){
        for(int j=1;j+k-1<=m;++j){
            /* cout<<"i= "<<i<<" j= "<<j<<" v= "<<f[i+k-1][j+k-1]-f[i+k-1][j-1]-f[i-1][j+k-1]+f[i-1][j-1]<<endl; */
            b.push_back((node){f[i+k-1][j+k-1]-f[i+k-1][j-1]-f[i-1][j+k-1]+f[i-1][j-1],i,j,i+k-1,j+k-1});
        }
    }
    sort(b.begin(),b.end());
    int cnt=0,ans=0;
    for(node i:b){
        if(cnt==3) break;
        bool flag=0;
        /* cout<<"sum= "<<i.sum<<' '<<i.xa<<' '<<i.ya<<endl; */
        for(int j=1;j<=cnt;++j){
            if((c[j].first<=i.xa&&i.xa<c[j].first+k&&c[j].second<=i.ya&&i.ya<c[j].second+k)||(c[j].first<=i.xb&&i.xb<c[j].first+k&&c[j].second<=i.yb&&i.yb<c[j].second+k)){
                flag=1;
                break;
            }
        }
        if(flag) continue;
        else c[++cnt]={i.xa,i.ya},ans+=i.sum;
    }
    printf("%d\n",ans);
    /* for(int i=1;i<=cnt;++i) cout<<c[i].first<<' '<<c[i].second<<'\n'; */
    return 0;
}
