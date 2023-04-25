#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
int T;
int p[30];
string s,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>s;
        int n=s.size();
        for(int i=0;i<26;++i) p[i]=0;
        for(int i=n-1;i>=0;--i){
            if(!p[s[i]-'a']) p[s[i]-'a']=i;
        }
        for(int i=1;i<26;++i){
            p[i]=max(p[i-1],p[i]);
        }
        int st=-1;
        for(int i=0;i<n;++i){
            if(s[i]=='a') continue;
            if(p[s[i]-'a'-1]>i){
                st=i;
                break;
            }
        }
        if(st==-1){
            cout<<s<<endl;
            continue;
        }
        ans=s;
        for(int i=st+1;i<n;++i){
            if(s[i]>=s[st]) continue;
            string tmp=s;
            reverse(tmp.begin()+st,tmp.begin()+i+1);
            if(tmp<ans) ans=tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}