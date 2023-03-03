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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int t,n;
string s,a;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        a="";
        for(int i=0;i<n;++i){
            if(s[i]>='a'&&s[i]<='z') s[i]-=32;
            if(i&&s[i]!=s[i-1]) a+=s[i];
            if(i==0) a+=s[i];
        }
        if(a!="MEOW") cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}