#include<iostream>
#include<cmath>
using namespace std;
int a[10004];
int n,aver,ans;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i],aver+=a[i];
    aver/=n;
    for(int i=0;i<n;++i) ans+=abs(a[i]-aver);
    cout<<ans/2<<endl;
    return 0;
}