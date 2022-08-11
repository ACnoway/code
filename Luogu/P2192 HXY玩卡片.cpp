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
int n,a,b;
int main()
{
    cin>>n;
    int x;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x==0) a++;
        else b++;
    }
    if(a&&b<9){
        cout<<0;
        return 0;
    }
    else if(a&&b>=9){
        for(int i=0;i<b/9*9;++i) cout<<5;
        for(int i=0;i<a;++i) cout<<0;
    }
    else cout<<"-1";
    return 0;
}