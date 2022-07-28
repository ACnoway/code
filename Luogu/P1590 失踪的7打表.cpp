#include <iostream>
#include <cstdio>
using namespace std;
int a[15]={0,1,9,81,729,6561,59049,531441,4782969,43046721,387420489};
int t;
int main()
{
    cin>>t;
    while(t--){
        string n;
        int ans=0;
        cin>>n;
        for(int i=0;i<n.size();++i){
            int k=n[i]-'0';
            cout<<k<<' ';
            ans+=k*a[n.size()-i];
            if(k>=7) ans-=a[n.size()-i];
        }
        cout<<endl<<ans<<endl;
    }
    return 0;
}