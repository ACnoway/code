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
int n;
int main()
{
    cin>>n;
    int mid=n>>1;
    cout<<(mid+1)*(n-mid+1)<<endl;
    return 0;
}