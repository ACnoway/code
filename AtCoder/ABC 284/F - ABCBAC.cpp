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
int v[30];
int n,cnt,i;
string s,t;
int main()
{
    cin>>n>>t;
    for(i=0;i<n;++i){
        s+=t[i];
        v[t[i]-'a']++;
        if(v[t[i]-'a']==1) cnt++;
        else if(v[t[i]-'a']==0) cnt--;
        v[t[i+n]-'a']--;
        if(v[t[i+n]-'a']==-1) cnt++;
        else if(v[t[i+n]-'a']==0) cnt--;
        if(cnt==0) break;
    }
    if(i==n){
        cout<<-1<<endl;
        return 0;
    }
    for(int j=n-1;j>i;--j) s+=t[j];
    cout<<s<<endl<<i+1<<endl;
    return 0;
}