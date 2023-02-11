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
long long t,n;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        if(n&1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}