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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int t,n,k,ans;
string a;
int C[27],c[27];
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>a;
        ans=0;
        for(int i=0;i<=26;++i) c[i]=C[i]=0;
        for(int i=0;i<n;++i){
            if(a[i]>='a'&&a[i]<='z'){
                if(C[a[i]-'a']) ans++,C[a[i]-'a']--;
                else c[a[i]-'a']++;
            }
            else{
                if(c[a[i]-'A']) ans++,c[a[i]-'A']--;
                else C[a[i]-'1A']++;
            }
        }
        for(int i=0;i<26&&k;++i){
            int x;
            if(c[i]){
                x=min(c[i]>>1,k);
                ans+=x;
                c[i]-=x;
                k-=x;
            }
            else if(C[i]){
                x=min(C[i]>>1,k);
                ans+=x;
                C[i]-=x;
                k-=x;
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}