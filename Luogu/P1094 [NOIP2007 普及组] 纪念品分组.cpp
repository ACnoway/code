#include <iostream>
#include <algorithm>
using namespace std;
int a[30004];
int main()
{
    int n,w;
    cin>>w>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    int l=0,r=n-1,ans=0;
    while(l<r){
        if(a[l]+a[r]>w) r--;
        else l++,r--;
        ans++;
    }
    if(l==r) ans++;
    cout<<ans<<endl;
    return 0;
}