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
int n,r,c;
string a;
int main()
{
    cin>>a;
    n=a.size();
    for(int i=floor(sqrt(n));i>=1;--i){
        if(n%i==0){
            r=i;
            c=n/i;
            break;
        }
    }
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j) cout<<a[j*r+i];
    }
    return 0;
}