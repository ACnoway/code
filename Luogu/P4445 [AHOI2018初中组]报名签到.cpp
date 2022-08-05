#include<iostream>
using namespace std;
int n;
int a[100005];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    long long ans=0;
    for(int i=1;i<n;++i) ans+=max(a[i-1],a[i]);
    cout<<ans<<endl;
    return 0;
}