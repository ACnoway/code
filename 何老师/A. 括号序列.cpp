#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#define int long long
using namespace std;
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int mod=1000000007;
const int maxn=10000007;
char s[maxn];
int top,cnt,neew[maxn],sum[maxn],st[maxn];
signed main()
{
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;++i){
        if(s[i]=='('){
            st[++top]=i;
        }
        else if(top){
            if(st[top]>=neew[1]){
                for(int j=1;j<=cnt;++j){
                    sum[neew[j]]++;
                    sum[i+1]--;
                }
            }
            sum[st[top]]++;
            sum[i+1]--;
            if(i<n&&s[i+1]=='(') neew[++cnt]=st[top];
            top--;
        }
        else cnt=0;
    }
    for(int i=1;i<=n;++i){
        sum[i]+=sum[i-1];
        sum[i]%=mod;
        //cout<<sum[i]<<endl;
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=((sum[i]%mod*i%mod)%mod);
    }
    write(ans);
    putchar('\n');
    return 0;
}