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
double h,s1,v,l,k,n;
int main()
{
    cin>>h>>s1>>v>>l>>k>>n;
    double ma=sqrt(h/5),mi=sqrt((h-k)/5);
    int a=int(s1+l-mi*v),b=int(s1-ma*v);
    a=min(a,(int)n);b=max(b,0);
    cout<<a-b<<endl;
    return 0;
}