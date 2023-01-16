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
int a,b;
int main()
{
    cin>>a>>b;
    if(b>>1==a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}