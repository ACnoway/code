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
int v,sv;
int main()
{
    cin>>v>>sv;
    if(sv>=v){
        cout<<0;
        return 0;
    }
    double num=(double)v/sv;
    if((int)num==num&&(int)num%2!=0){
        cout<<0;
        return 0;
    }
    if(sv==1){
        cout<<v/(2*sv);
        return 0;
    }
    cout<<int(v/(2*sv)+0.5);
    return 0;
}