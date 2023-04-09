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
int a=-1,b=-1,c=-1,d=-1,e=-1;
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]=='B'){
            if(a==-1) a=i;
            else b=i;
        }
        else if(s[i]=='R'){
            if(c==-1) c=i;
            else d=i;
        }
        else if(s[i]=='K'){
            e=i;
        }
    }
    if(c>d) swap(c,d);
    if(((a&1)!=(b&1))&&e>c&&e<d){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;  
    return 0;
}