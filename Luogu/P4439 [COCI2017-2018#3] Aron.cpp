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
char c,l;
int n;
int main()
{
    cin>>n;
    int ans=1;
    for(int i=0;i<n;++i){
        cin>>c;
        if(i>0){
            if(c!=l) ans++;
        }
        l=c;
    }
    cout<<ans+1<<endl;
    return 0;
}