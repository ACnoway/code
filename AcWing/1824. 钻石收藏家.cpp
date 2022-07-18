#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,k,s=0,e=1,ans=0;
    int a[1003];
    cin>>n>>k;
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    while(e<n){
        if(a[e++]-a[s]<=k) ans=max(ans,e-s);
        else s++;
    }
    cout<<ans<<endl;
    return 0;
}