#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,cnt;
unordered_map<string,int> m;
int rudu[200005],chudu[200005],p[200005];
int find(int x){
    //if(p[x]!=x) p[x]=find(x);
    return p[x];
}
void merge(int x,int y){
    if(find(x)!=find(y)) p[x]=find(y);
}
string s,t;
int main()
{
    cin>>n;
    for(int i=0;i<=n+n;++i) p[i]=i;
    for(int i=1;i<=n;++i){
        cin>>s>>t;
        if(!m[s]) m[s]=++cnt;
        if(!m[t]) m[t]=++cnt;
        merge(m[t],m[s]);
        chudu[m[s]]++;
        rudu[m[t]]++;
    }
    int ans=0;
    for(int i=1;i<=cnt;++i){
        if(chudu[i]==0) ans++;
    }
    for(int i=1;i<=cnt;++i){
        ans-=(p[i]==i);
    }
    if(ans==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}