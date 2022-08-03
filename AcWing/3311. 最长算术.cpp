#include<iostream>
#include<cmath>
using namespace std;
int a[200005];
int t,n;
int main()
{
    cin>>t;
    int c,ans,cnt;
    for(int tt=1;tt<=t;++tt){
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        c=a[2]-a[1];
        cnt=2;
        ans=2;
        for(int i=3;i<=n;++i){
            if(a[i]-a[i-1]!=c){
                c=a[i]-a[i-1];
                ans=max(ans,cnt);
                cnt=2;
            }
            else cnt++;
        }
        ans=max(ans,cnt);
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}