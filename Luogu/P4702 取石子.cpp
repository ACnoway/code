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
int n,a;
long long cnt;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a;
        cnt+=a;
    }
    if(cnt&1) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    return 0;
}