#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int t,n,ma,ne,x;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        ma=0;ne=0;
        for(int i=0;i<n;++i){
            cin>>x;
            if(x>ma) ne=ma,ma=x;
            else if(x>ne) ne=x;
        }
        if(ma-2>=ne) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}