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
char a[103][103];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) cin>>a[i][j];
    }
    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]=='*'&&(!i||a[i-1][j]=='.')&&(!j||a[i][j-1]=='.')) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}