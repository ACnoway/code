#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
int n;
string s,tmp;
int main()
{
    cin>>n;
    cin>>s;
    int st,flag=0;
    for(int i=1;i<=n;++i){
        flag=0;
        for(int j=0;j<=n-i;++j){
            tmp=s.substr(j,i);
            st=s.find(tmp,0)+i;
            for(int k=j+1;k<=n-i;++k){
                if(tmp==s.substr(k,i)) flag++;
            }
        }
        if(flag==0){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}