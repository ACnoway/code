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
int x,h;
int main()
{
    x=read(); h=read();
    if(x<10) cout<<"Drizzle"<<endl;
    else if(x<25) cout<<"Moderate Rain"<<endl;
    else if(x<50) cout<<"Heavy Rain"<<endl;
    else cout<<"Torrential Rain"<<endl;
    if(h==1&&x>=20) cout<<"YES"<<endl;
    else if(h==1) cout<<"NO"<<endl;
    return 0;
}