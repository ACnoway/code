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
double x,z,c;
int main()
{
    cin>>x>>z>>c;
    cout<<ceil((x-2*z)/c)<<endl;
    return 0;
}