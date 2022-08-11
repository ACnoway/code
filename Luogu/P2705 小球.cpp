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
int r,b,c,d,e;
int main()
{
    cin>>r>>b>>c>>d>>e;
    if(c+d>e+e) cout<<r*c+b*d<<endl;
    else{
        if(r>b) cout<<b*e*2+(r-b)*c;
        else cout<<r*e*2+(b-r)*d;
    }
    return 0;
}