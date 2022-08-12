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
int a[2000006];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    int x;
    while(m--){
        cin>>x;
        cout<<a[x]<<endl;
    }
    return 0;
}