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
int x,tmp,a,ap;
int main()
{
    for(int i=0;i<5;++i){
        x=0;
        for(int j=0;j<4;++j) cin>>tmp,x+=tmp;
        if(x>a){
            a=x;
            ap=i+1;
        }
    }
    cout<<ap<<' '<<a<<endl;
    return 0;
}