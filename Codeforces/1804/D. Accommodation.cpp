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
int n,m,ans,ama,c1,c2,c3;
string s;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>s;
        c1=c2=c3=0;
        for(int j=0;j<m;++j){
            if(s[j]=='1'){
                c1++;
            }
            if(j&&s[j]=='1'&&s[j-1]=='1'){
                c2++;
            }
            if(j&&s[j]=='0'&&s[j-1]=='0'){
                c3++;
            }
        }
        if(c2>=m/4){
            ans+=m/4+c1-c2*2;
        }
        else{
            ans+=min(m/4,c1)+max(0,c1-m/4+c2);
        }
        //c1=m-c1;
        if(c3>=m/4){
            ama+=c1;
        }
        else{
            ama+=m/4-c3+max(0,c1-m/4+c3);
        }
    }
    cout<<ans<<' '<<ama<<endl;
    return 0;
}