#include<iostream>
#define int long long
using namespace std;
signed main()
{
    int t,l,r,x,d;
    cin>>t;
    while(t--){
        cin>>l>>r>>x;
        if(l/x!=r/x) cout<<"1"<<endl;
        else cout<<l/x<<endl;
    }
    return 0;
}