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
double n;
double a[1003];
double pj,fc;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pj+=a[i];
    }
    pj/=(double)n;
    for(int i=1;i<=n;++i) fc+=pow(a[i]-pj,2);
    fc/=(double)n;
    for(int i=1;i<=n;++i) cout<<(a[i]-pj)/sqrt(fc)<<endl;
    return 0;
}