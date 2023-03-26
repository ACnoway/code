#include<iostream>
#define int long long
using namespace std;
int a[200005];
signed main()
{
    int n;
    string s;
    cin>>n;
    getchar();
    cin>>s;
    a[1]=1;
    for(int i=0;i<n;++i){
        if(s[i]=='1'){
            for(int j=2;j<=n;j+=2){
                a[j]+=a[j-1];
                a[j]%=998244353;
            }
        }
        else{
            for(int j=1;j<=n;j+=2){
                a[j]+=a[j-1];
                a[j]%=998244353;
            }
        }
        
    }
    long long ans=1;
    for(int i=1;i<=n;++i) ans=(ans*(a[i]+1))%998244353;
    cout<<ans<<endl;
    return 0;
}