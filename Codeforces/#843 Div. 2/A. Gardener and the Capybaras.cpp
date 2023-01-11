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
int t;
string s;
int flag;
int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        flag=0;
        for(int i=1;i<s.size()-1;++i){
            if(s[i]=='a'){
                flag=i;
                break;
            }
        }
        if(flag){
            for(int i=0;i<flag;++i) putchar(s[i]);
            putchar(' ');
            putchar('a');
            putchar(' ');
            for(int i=flag+1;i<s.size();++i) putchar(s[i]);
        }
        else{
            putchar(s[0]);
            putchar(' ');
            for(int i=1;i<s.size()-1;++i) putchar(s[i]);
            putchar(' ');
            putchar(s[s.size()-1]);
        }
        putchar('\n');
    }
    return 0;
}