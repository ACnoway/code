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
int a[10];
string s;
int main()
{
    cin>>s;
    int n;
    for(int i=s.size()-1;i>0;--i){
        if(s[i]>='0'&&s[i]<='9'){n=s[i]-'0';break;}
    }
    if(s[0]!='M'||s[1]!='D'||s[2]!='A') cout<<"1 1 1 1 1";
    else{
        for(int i=1;i<=5;++i){
            if(i==5&&n==0) cout<<"1 ";
            else if(n==i||n==10-i) cout<<"1 ";
            else cout<<"0 ";
        }
    }
    return 0;
}