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
int n,m,k,a;
int main()
{
    cin>>n>>m>>k;
    int now=0,t=0;
    if(k){
        cin>>a;
        k--;
    }
    while(1){
        now+=m;
        ++t;
        if(now>=n){
            cout<<t<<endl;
            return 0;
        }
        if(now==a) m++;
        if(now>=a&&k>0){
            k--;
            cin>>a;
        }
    }
    return 0;
}