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
int n,ans,ma;
bool v[20000007];
int main()
{
    cin>>n;
    int x;
    for(int i=0;i<n;++i){
        cin>>x;
        ma=max(ma,x);
        if(v[x]){
            ans++;
        }
        else{
            v[x]=1;
            ans+=6;
        }
    }
    ans+=ma*10;
    cout<<ans<<endl;
    return 0;
}