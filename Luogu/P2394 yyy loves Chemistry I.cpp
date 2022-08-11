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
long double x;
int main()
{
    //    提高输入精度
    scanf("%15Lf",&x);
    printf("%.8Lf",x/23.0);
    return 0;
}