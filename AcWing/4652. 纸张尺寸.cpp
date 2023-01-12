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
int a,b,c;
int main()
{
    scanf("A%d",&c);
    a=1189;b=841;
    for(int i=1;i<=c;++i){
        a>>=1;if(a<b) swap(a,b);
    }
    cout<<a<<endl<<b<<endl;
    return 0;
}