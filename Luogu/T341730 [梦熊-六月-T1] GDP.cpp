#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
double c,i,g,m,x;
int main()
{
    scanf("%lf%lf%lf%lf%lf",&c,&i,&g,&m,&x);
    printf("%.2lf\n",c+i+g+x-m);
    return 0;
}