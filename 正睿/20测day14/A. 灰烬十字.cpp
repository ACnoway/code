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
int n;
bool d1[8003],d2[8003];
int dfs(int now,int all){
    if(now>all){
        return 1;
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(!d1[])
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n+n;++i){
        cout<<dfs(1,i)<<' ';
    }
    return 0;
}