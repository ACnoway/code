#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int unsigned long long
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
const int N=30004,base=131;
int n,m;
string s[N];
int a[N],t[N],mi[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    mi[0]=1;
    for(int i=1;i<=m;++i) mi[i]=mi[i-1]*base;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        for(int j=0;j<m;++j){
            a[i]=a[i]*base+s[i][j]-'a'+1;
        }
    }
    int ans=0;
    for(int j=0;j<m;++j){
        for(int i=1;i<=n;++i){
            t[i]=a[i]-(s[i][j]-'a'+1)*mi[m-j-1];
        }
        sort(t+1,t+1+n);
        int tmp=1;
        for(int i=1;i<n;++i){
            if(t[i]!=t[i+1]) tmp=1;
            else{
                ans+=tmp;
                ++tmp;
            }
        }
    }
    printf("%Ld\n",ans);
    return 0;
}