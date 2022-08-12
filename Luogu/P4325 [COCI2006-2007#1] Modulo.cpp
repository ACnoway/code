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
int a;
int t[45];
int main()
{
    for(int i=0;i<10;++i){
        cin>>a;
        t[a%42]=1;
    }
    int ans=0;
    for(int i=0;i<42;++i) ans+=t[i];
    cout<<ans<<endl;
    return 0;
}