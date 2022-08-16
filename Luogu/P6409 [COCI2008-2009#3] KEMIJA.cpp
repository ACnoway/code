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
    while(cin>>s){
        for(int i=0;i<s.size();++i){
            cout<<s[i];
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') i+=2;
        }
        cout<<' ';
    }
    return 0;
}