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
int a,b,c,d,e,f;
int main()
{
    cin>>a>>b>>c>>d>>e>>f;
    if(a==c) cout<<e<<' ';
    else if(a==e) cout<<c<<' ';
    else if(c==e) cout<<a<<' ';
    if(b==d) cout<<f<<endl;
    else if(b==f) cout<<d<<endl;
    else if(d==f) cout<<b<<endl;
    return 0;
}