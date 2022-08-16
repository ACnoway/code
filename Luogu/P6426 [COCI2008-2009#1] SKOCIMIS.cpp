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
int a[3];
int main()
{
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cout<<max(a[1]-a[0],a[2]-a[1])-1<<endl;
    return 0;
}