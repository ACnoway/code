#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<unordered_map>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
const int maxn=100005,mod=1000000007;
int n,ca,cb;
long long jc[maxn];
struct node{
    int a,b;
}a[maxn];
unordered_map<int,int> ma,mb;
int am[maxn],bm[maxn];
//int t[maxn];
//vector<int> v[maxn];
bool cmp(node x,node y){
    if(x.a!=y.a) return x.a<y.a;
    return x.b<y.b;
}
inline long long ksm(int a,int b){
    long long ans=1;
    while(b){
        if(b&1) ans*=a,ans%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return ans%mod;
}
int main()
{
    n=read();
    jc[0]=1;
    for(int i=1;i<=n;++i) jc[i]=(jc[i-1]*i)%mod;
    for(int i=1;i<=n;++i){
        a[i].a=read();
        a[i].b=read();
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i){
        if(!ma[a[i].a]) ma[a[i].a]=++ca,am[ca]=i;
        if(!mb[a[i].b]) mb[a[i].b]=++cb,bm[cb]=i;
        //v[ca].push_back(a[i].b);
        //t[mb[a[i].b]]++;
    }
    am[ca+1]=n+1;
    bm[cb+1]=n+1;
    //for(int i=cb;i;--i) t[i]+=t[i+1];
    a[0].a=-1;
    a[0].b=-1;
    long long ans=0,cnt=0;
    for(int i=1;i<=n;++i){
        cnt=0;
        for(int j=ma[a[i].a]+1;j<=ca;++j){
            for(int k=am[j];k<am[j+1];++k){
                if(a[k].b>a[i].b){
                    cnt+=am[j+1]-k;
                    break;
                }
                ans+=
            }
        }
    }
    return 0;
}