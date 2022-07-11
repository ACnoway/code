#include<iostream>
using namespace std;
int a[1003],f[1003];
int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        f[i]=1;
        for(int j=1;j<i;++j){
            if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);
        }
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}