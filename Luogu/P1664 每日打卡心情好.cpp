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
int n,now,ans,mis;
int a[10]={1,3,7,30,120,365,99999};
int main()
{
    cin>>n;
    int x;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x){
            if(mis) now-=pow(2,mis-1);
            debug(now);
            if(now<0) now=0;
            mis=0;
            now++;
            for(int j=0;j<7;++j){
                if(now<a[j]){
                    ans+=j;
                    break;
                }
            }
        }
        else mis++;
        debug(ans);
    }
    cout<<ans<<endl;
    return 0;
}