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
int n,k;
int dfs(int x){
    if(x-k>0&&(x-k)%2==0) return dfs((x+k)/2)+dfs((x-k)/2);
    else return 1;
}
int main()
{
    cin>>n>>k;
    cout<<dfs(n)<<endl;
    return 0;
}