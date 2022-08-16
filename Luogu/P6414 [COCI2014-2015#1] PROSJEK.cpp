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
int a[200],b[200];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>b[i];
        cout<<b[i]*i-b[i-1]*(i-1)<<' ';
    }
    return 0;
}