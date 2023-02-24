#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define int long long
using namespace std;
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int mod=1000000007;
const int maxn=10000007;
int n;
int zuo[maxn],you[maxn];
int st[maxn],top;
char s[maxn];
signed main()
{
    cin>>s+1;
    n=strlen(s+1);
    for(int i=1;i<=n;++i){
        if(s[i]=='('){
            zuo[i]=(s[i-1]==')'?zuo[i-1]+1:1);
            st[++top]=i;
        }
        else{
            zuo[i]=zuo[st[top]];
            if(top) top--;
        }
    }
    top=0;
    for(int i=n;i;--i){
        if(s[i]==')'){
            you[i]=(s[i+1]=='('?you[i+1]+1:1);
            st[++top]=i;
        }
        else{
            you[i]=you[st[top]];
            if(top) top--;
        }
    }
    int ans=0,f=0;
    for(int i=1;i<=n;++i){
        if(s[i]=='('){
            f=(f+1ll*zuo[i]*you[i]%mod)%mod;
        }
        ans=ans+1ll*(i*f)%mod;
        if(s[i]==')'){
            f=(f-1ll*zuo[i]*you[i]%mod+mod)%mod;
        }
    }
    write(ans);
    putchar('\n');
    return 0;
}