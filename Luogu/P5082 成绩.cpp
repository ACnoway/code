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
typedef long long ll;
ll n,x,a,b,c;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        a+=x;
    }
    for(int i=0;i<n;++i){
        cin>>x;
        b+=x;
    }
    printf("%.6lf",(double)(a*3-b*2)/(a-b));
    return 0;
}