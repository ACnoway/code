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
double n,t,money;
int main()
{
    cin>>n;
    for(int i=n-1;~i;--i){
        t+=n/(n-(double)i);
        money+=(double)i/(n-(double)i)*(t+1)+t-n/(n-(double)i)+1;
    }
    printf("%.2lf\n",money);
    return 0;
}