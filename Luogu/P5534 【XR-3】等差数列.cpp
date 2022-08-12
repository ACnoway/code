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
long long a,b,c,n;
int main()
{
    cin>>a>>b>>n;
    cout<<(a+(a+(n-1)*(b-a)))*n/2<<endl;
    return 0;
}