#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
long double ans,a;
int main()
{
    while(cin>>a){
        ans+=a*100000;
    }
    cout<<fixed<<setprecision(5)<<ans/100000;
    return 0;
}