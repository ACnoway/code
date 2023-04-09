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
int n,m;
string s;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>s;
        for(int j=0;j<s.size();++j){
            if(j+1<s.size()&&s[j]=='T'&&s[j+1]=='T'){
                putchar('P');
                putchar('C');
                ++j;
            }
            else putchar(s[j]);
        }
        putchar('\n');
    }
    return 0;
}