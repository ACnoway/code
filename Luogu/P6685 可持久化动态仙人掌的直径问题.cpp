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
int n,m,ans;
int main()
{
    cin>>n>>m;
    cout<<(int)floor(pow(n,1.0/m));
    return 0;
}