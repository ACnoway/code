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
int n,m;
int a[1003];
int main()
{
    cin>>n>>m;
    int ans=0,sum=0;
    for(int i=0;i<m;++i) cin>>a[i];
    sort(a,a+m);
    for(int i=0;i<m;++i){
        if(n>=m-i){
            if(a[i]*(m-i)>ans){
                sum=a[i];
                ans=a[i]*(m-i);
            }
        }
    }
    cout<<sum<<' '<<ans<<endl;
    return 0;
}