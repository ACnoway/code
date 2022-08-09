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
int n,ans,xa,ya,xb,yb;
int x[100],y[100],r[100];
double dis(int ax,int ay,int bx,int by){
    return sqrt(pow(bx-ax,2)+pow(by-ay,2));
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>x[i];
    for(int i=1;i<=n;++i) cin>>y[i];
    for(int i=1;i<=n;++i) cin>>r[i];
    cin>>xa>>ya>>xb>>yb;
    for(int i=1;i<=n;++i){
        if((dis(xa,ya,x[i],y[i])<r[i])^(dis(xb,yb,x[i],y[i])<r[i])) ans++;
    }
    cout<<ans<<endl;
    return 0;
}