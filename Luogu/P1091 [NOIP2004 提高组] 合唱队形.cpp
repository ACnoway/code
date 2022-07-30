#include<iostream>
using namespace std;
int a[200],f1[200],f2[200];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        f1[i]=1;
        for(int j=1;j<i;++j){
            if(a[i]>a[j]) f1[i]=max(f1[i],f1[j]+1);
        }
    }
    for(int i=n;i>0;--i){
        f2[i]=1;
        for(int j=n;j>i;--j){
            if(a[i]>a[j]) f2[i]=max(f2[i],f2[j]+1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,f1[i]+f2[i]-1);
    cout<<n-ans<<endl;
    return 0;
}