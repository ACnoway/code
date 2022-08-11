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
int v[10004];
int n;
int t[10004];
int main()
{
    cin>>n;
    for(int i=2;i<=n;++i){
        int tmp=i;
        for(int j=2;j<=i;++j){
            while(tmp%j==0){
                tmp/=j;
                t[j]++;
            }
        }
    }
    for(int i=2;i<=n;++i){
        if(t[i]) cout<<i<<' '<<t[i]<<endl;
    }
    return 0;
}