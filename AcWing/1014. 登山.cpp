#include<iostream>
using namespace std;
int n,ans;
int a[1003],f1[1003],f2[1003];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        f1[i]=1;
        for(int j=1;j<i;++j){
            if(a[j]<a[i]) f1[i]=max(f1[i],f1[j]+1);
        }
    }
    for(int i=n;i>0;--i){
        f2[i]=1;
        for(int j=n;j>i;--j){
            if(a[j]<a[i]) f2[i]=max(f2[i],f2[j]+1);
        }
    }
    for(int i=1;i<=n;++i) ans=max(ans,f1[i]+f2[i]-1);
    cout<<ans<<endl;
    return 0;
}