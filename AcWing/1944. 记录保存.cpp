#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n;
map<string,int> m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        string a[3];
        for(int j=0;j<3;++j) cin>>a[i];
        sort(a,a+3);
        string s=a[0]+' '+a[1]+' '+a[2];
        m[s]++;
    }
    int ans=0;
    for(auto i:m){
        ans=max(ans,i.second);
    }
    cout<<ans;
    return 0;
}