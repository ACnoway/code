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
int n,ma,mi,ans,res;
int asc[125];
string s;
int main()
{
    cin>>n;
    while(n--){
        cin>>s;
        ma=30;mi=122;ans=0;
        for(int i=ma;i<=mi;++i) asc[i]=0;
        for(int i=0;i<s.size();++i){
            ma=max(ma,(int)s[i]);
            mi=min(mi,(int)s[i]);
            asc[(int)s[i]]++;
        }
        debug(ma);debug(mi);
        ans=1145141919;
        for(int i=mi;i<=ma;++i){
            res=0;
            for(int j=mi;j<=ma;++j){
                res+=abs(j-i)*asc[j];
            }
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}