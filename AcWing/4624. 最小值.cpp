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
int t,a,b;
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<min(a,min(b,(a+b)/3))<<endl;
    }
    return 0;
}