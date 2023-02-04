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
string ans[6]={
    "",
    "B",
    "A",
    "8",
    "50",
    "6,5,4,3,2,1,\n",
};
int main()
{
    int t;
    cin>>t;
    cout<<ans[t];
    return 0;
}
/* 
00101100
00010101
01000001

7 0 0
6 1 0
5 1 1
5 2 0
4 2 1
4 3 0
3 2 2
3 3 1
*/