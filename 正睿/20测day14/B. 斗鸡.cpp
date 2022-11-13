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
int a[200005][2];
int main()
{
    cin>>n>>m;
    for(int i=0;i<2*m;++i) cin>>a[i][0]>>a[i][1];
    
    cout<<-1<<endl;
    return 0;
}