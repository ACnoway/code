#include <iostream>
using namespace std;
int a[200],f[200];
int n,aver;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],aver+=a[i];
    aver/=n;
    for(int i=1;i<=n;++i){
        a[i]-=aver;
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        if(a[i]==0){
            continue;
        }
        a[i+1]+=a[i];
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}