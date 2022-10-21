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
int n;
int a[20];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    long long ans=0;
    do{
        bool flag=1;
        for(int i=1;i<n;++i){
            if((double)sqrt(a[i]+a[i+1])!=floor(sqrt(a[i]+a[i+1]))){
                flag=0;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans<<endl;
    return 0;
}