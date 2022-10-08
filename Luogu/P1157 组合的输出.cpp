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
    
}
int main()
{
    
    return 0;
}