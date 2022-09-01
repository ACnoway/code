#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int p[1003];
int n;
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n;
    int ans=0,x;
    for(int i=0;i<=n;++i) p[i]=i;
    for(int i=1;i<=n;++i){
        cin>>x;
        if(find(x)!=find(i)) p[find(i)]=find(x);
    }
    for(int i=1;i<=n;++i){
        if(find(i)==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}