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
string a,b,c,d;
int main()
{
    cin>>a>>b;
    int st;
    for(st=0;st<a.size();++st){
        if(a[st]=='.') break;
    }
    for(;st<a.size();++st){
        c+=a[st];
    }
    for(st=0;st<b.size();++st){
        if(b[st]=='.') break;
    }
    for(;st<b.size();++st){
        d+=b[st];
    }
    if(c!=d) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}