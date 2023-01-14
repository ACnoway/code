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
int n,a,ans[3];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a;
        ans[i%3]+=a;
    }
    if(ans[0]>ans[1]&&ans[0]>ans[2]) cout<<"chest"<<endl;
    else if(ans[1]>ans[0]&&ans[1]>ans[2]) cout<<"biceps"<<endl;
    else cout<<"back"<<endl;
    return 0;
}