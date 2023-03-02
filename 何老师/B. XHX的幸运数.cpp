#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
const int maxn=100005;
int n,ans;
char s[maxn];
int top,st[maxn];
signed main()
{
    cin>>n;
    cin>>s+1;
    for(int i=1;i<=n;++i){
        if(s[i]=='4') st[++top]=i;
        else{
            ans+=st[top--];
        }
    }
    write(ans);
    putchar('\n');
    return 0;
}