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
int a,b,c,d,e,f,g,h,i;
int main()
{
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
    if(50+a+b+c+d+e+f+g+h*5>=i) cout<<"AKIOI";
    else cout<<"AFO";
    return 0;
}