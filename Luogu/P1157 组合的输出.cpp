#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,r;
int a[30];
void dfs(int x,int y){
    if(y-1==r){
        for(int i=1;i<=r;++i) cout<<setw(3)<<a[i];
        cout<<endl;
        return;
    }
    if(n-x<r-y+1) return;
    for(int i=x+1;i<=n;++i){
        a[y]=i;
        dfs(i,y+1);
    }
}
int main()
{
    cin>>n>>r;
    dfs(0,1);
    return 0;
}