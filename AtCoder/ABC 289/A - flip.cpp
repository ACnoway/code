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
int main()
{
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]=='0') putchar('1');
        else putchar('0');
    }
    putchar('\n');
    return 0;
}