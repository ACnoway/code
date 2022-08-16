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
int a[103];
string name[103],s;
int cnt,n;
int main()
{
    cin>>n;
    int ans,tmp;
    for(int i=0;i<n;++i){
        cin>>name[i]>>s;
        tmp=0;
        for(int j=2;j<s.size();++j){
            if(s[j-2]=='s'&&s[j-1]=='o'&&s[j]=='s') tmp++;
        }
        if(tmp>ans){
            cnt=0;
            a[cnt++]=i;
            ans=tmp;
        }
        else if(tmp==ans){
            a[cnt++]=i;
        }
    }
    for(int i=0;i<cnt;++i){
        cout<<name[a[i]]<<' ';
    }
    cout<<endl<<ans;
    return 0;
}