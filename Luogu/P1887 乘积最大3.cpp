//看了一圈题解，好像我这个是个新解法，但是懒得写题解了t
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
double n,m,aver;
int main()
{
    cin>>n>>m;
    aver=n/m;
    while(n&&m){
        cout<<floor(aver)<<' ';
        n-=floor(aver);
        m--;
        aver=n/m;
    }
    return 0;
}