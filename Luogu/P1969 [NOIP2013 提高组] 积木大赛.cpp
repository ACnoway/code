#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    int last=0,now=0;
    for(int i=1;i<=n;++i){
        cin>>now;
        if(now>last) ans+=now-last;
        last=now;
    }
    cout<<ans<<endl;
    return 0;
}