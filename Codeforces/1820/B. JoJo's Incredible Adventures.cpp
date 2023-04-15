#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
int t;
string s;
signed main()
{
    cin>>t;
    while(t--){
        cin>>s;
        int cnt=0,sum=0;
        s+=s;
        for(int i=0;i<s.size();++i){
            if(s[i]=='0'){
                sum=max(sum,cnt);
                cnt=0;
            }
            else ++cnt;
        }
        sum=max(sum,cnt);
        if(sum==s.size()){
            sum>>=1;
            cout<<sum*sum<<endl;
            continue;
        }
        cout<<(sum%2==1?(sum/2+1)*(sum/2+1):sum/2*(sum/2+1))<<endl;
    }
    return 0;
}