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
    for(int i=1;i*i<=n;++i){
        cout<<i*i<<' ';
    }
    return 0;
}