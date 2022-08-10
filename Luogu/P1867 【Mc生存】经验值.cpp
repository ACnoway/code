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
int n,l;
double hp=10,xp=0;
int main()
{
    cin>>n;
    double hpx,xpx;
    while(n--){
        cin>>hpx>>xpx;
        hp-=hpx;
        if(hp<=0) break;
        else if(hp>10) hp=10;
        xp+=xpx;
    }
    while(xp>=(1<<l)){
        xp-=(1<<l);
        l++;
    }
    cout<<l<<' '<<xp<<endl;
    return 0;
}