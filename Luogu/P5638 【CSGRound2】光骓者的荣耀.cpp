#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[1000006];
int n,k;
int main()
{
    cin>>n>>k;
    for(int i=2;i<=n;++i){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    long long ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,a[i+k]-a[i]);
    }
    cout<<a[n]-ans;
    return 0;
}