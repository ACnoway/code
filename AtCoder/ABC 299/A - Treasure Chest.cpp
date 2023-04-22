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
int n;
string s;
int main()
{
    cin>>n>>s;
    int a=s.find('|'),b=s.find('*'),c=s.find('|',a+1);
    if(a<b&&b<c) cout<<"in"<<endl;
    else cout<<"out"<<endl;
    return 0;
}