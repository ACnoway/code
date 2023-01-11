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
string s[11];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i];
    for(int i=n;i;--i)cout<<s[i]<<endl;
    return 0;
}