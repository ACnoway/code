#include <iostream>
#include <cstdio>
using namespace std;
int x[100005],y[100005];
int n,ans,all;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
    for(int i=2;i<=n;++i) all+=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
    //cout<<all<<endl;
    for(int i=1;i<n-1;++i){
        ans=max(ans,abs(x[i+1]-x[i])+abs(y[i+1]-y[i])+abs(x[i+1]-x[i+2])+abs(y[i+1]-y[i+2])-abs(x[i+2]-x[i])-abs(y[i+2]-y[i]));
    }
    cout<<all-ans;
    return 0;
}