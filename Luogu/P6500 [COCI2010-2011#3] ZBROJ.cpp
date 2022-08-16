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
int a,b,s1,s2;
int main()
{
    cin>>a>>b;
    for(int s=1,x=a;x;x/=10,s*=10){
        if(x%10==5) s1+=s;
        else if(x%10==6) s2+=s;
    }
    for(int s=1,x=b;x;x/=10,s*=10){
        if(x%10==5) s1+=s;
        else if(x%10==6) s2+=s;
    }
    cout<<a+b-s2<<' '<<a+b+s1<<endl;
    return 0;
}