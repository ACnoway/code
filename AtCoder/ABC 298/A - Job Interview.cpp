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
int n,cnt,flag;
string s;
int main()
{
    cin>>n>>s;
    for(int i=0;i<n;++i){
        if(s[i]=='x'){
            flag=-1;
            cout<<"No"<<endl;
            return 0;
        }
        else if(s[i]=='o'&&flag!=-1) flag=1;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}