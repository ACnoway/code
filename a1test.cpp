#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const int maxn=10000007;
int n,k,cnt,ans=-maxn;
int a[maxn],t[maxn];
struct node{
    int v,p;
}fa[maxn],fb[maxn];
int get(int x){
    int l=fa[x].p,r=fb[x].p;
    int cc=t[r]-t[l-1];
    return a[r]-a[l-1]+(cc>k?k-cc+k:cc);
}
int get1(int x){
    int l=fa[x].p,r=fb[x-1].p;
    if(l>r) return -maxn;
    int cc=t[r]-t[l-1];
    return a[r]-a[l-1]+(cc>k?k-cc+k:cc);
}
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
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i){
        cout<<(int)s[i]<<endl;
    }
    return 0;
}