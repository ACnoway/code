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
int s,r1;
int main()
{
    cin>>r1>>s;
    cout<<s*2-r1<<endl;
    return 0;
}