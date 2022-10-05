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
#define int long long
int n,q,cnt,x;
bool flag=0;
string a[200005];
string b[100005];
signed main()
{
    cin>>n;
    string s;
    for(int i=0;i<n;++i){
        cin>>b[i];
        s=b[i];
        if(s=="CapsLock") flag=!flag;
        else{
            if(flag){
                for(int j=0;j<s.size();++j){
                    if(s[j]>='A'&&s[j]<='Z') s[j]+=32;
                    else if(s[j]>='a'&&s[j]<='z') s[j]-=32;
                }
            }
            a[cnt++]=s;
        }
    }
    for(int i=0;i<n;++i){
        s=b[i];
        if(s=="CapsLock") flag=!flag;
        else{
            if(flag){
                for(int j=0;j<s.size();++j){
                    if(s[j]>='A'&&s[j]<='Z') s[j]+=32;
                    else if(s[j]>='a'&&s[j]<='z') s[j]-=32;
                }
            }
            a[cnt++]=s;
        }
    }
    cin>>q;
    while(q--){
        cin>>x;
        --x;
        cout<<a[x%cnt]<<endl;
    }
    return 0;
}