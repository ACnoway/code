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
int T,n;
int a[200005];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>s;
        for(int i=0;i<n;++i) a[i]=n-i;
        int ed=0;
        for(int i=0;i<n-1;i=ed){
            while(s[ed]=='<') ++ed;
            ++ed;
            reverse(a+i,a+ed);
        }
        for(int i=0;i<n;++i) cout<<a[i]<<' ';
        cout<<endl;
        for(int i=0;i<n;++i) a[i]=i+1;
        ed=0;
        for(int i=0;i<n-1;i=ed){
            while(s[ed]=='>') ++ed;
            ++ed;
            reverse(a+i,a+ed);
        }
        for(int i=0;i<n;++i) cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}