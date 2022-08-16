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
string s;
int a[4];
int main()
{
    cin>>s;
    a[1]=1;
    for(int i=0;i<s.size();++i){
        if(s[i]=='A') swap(a[1],a[2]);
        if(s[i]=='B') swap(a[2],a[3]);
        if(s[i]=='C') swap(a[1],a[3]);
    }
    if(a[1]) cout<<1;
    else if(a[2]) cout<<2;
    else cout<<3;
    return 0;
}