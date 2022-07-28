#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[2000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int ans=2147483600;
    for(int i=0;i<84;++i){
        int temp=0,l=i,r=i+17;
        for(int j=0;j<n;++j){
            if(a[j]<l) temp+=(l-a[j])*(l-a[j]);
            else if(a[j]>r) temp+=(a[j]-r)*(a[j]-r);
        }
        ans=min(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}