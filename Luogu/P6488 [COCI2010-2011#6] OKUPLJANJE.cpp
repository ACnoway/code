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
long long a,b,s;
int main()
{
    cin>>a>>b;
    for(int i=0;i<5;++i) cin>>s,cout<<s-(a*b)<<' ';
    return 0;
}