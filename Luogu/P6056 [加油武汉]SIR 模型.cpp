//! 一定要注意for里面判断条件的变量名别跟外面的重了
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
int s,i,r,n;
double b,g;
int main()
{
    cin>>s>>i>>n;
    cin>>b>>g;
    int ni,nr;
    for(int I=1;I<=n;++I){
        ni=min(s,(int)ceil(b*s*i));
        nr=(int)ceil(g*i);
        s-=ni;
        i+=ni;
        i-=nr;
        r+=nr;
        if(s<0) s=0;
        if(i<0) i=0;
    }
    cout<<s<<' '<<i<<' '<<r;
    return 0;
}