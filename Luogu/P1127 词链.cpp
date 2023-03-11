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
const int N=1003;
int n,sum;
string a[N],now[N],ans[N];
int m[N];
int chu[130],ru[130];
bool flag,vis[N];
void dfs(int bef,int step){
    if(flag) return;
    if(step==n){
        flag=1;
        for(int i=1;i<=sum;++i) ans[i]=now[i];
        return;
    }
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        if(a[bef][a[bef].length()-1]==a[i][0]){
            now[++sum]=a[i];
            vis[i]=1;
            dfs(i,step+1);
            sum--;
            vis[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        m[i]=a[i].size()-1;
        chu[a[i][0]]++;
        ru[a[i][m[i]]]++;
    }
    int st=1;
    sort(a+1,a+1+n);
    int s,t;
    for(int i='a';i<='z';++i){
        if(chu[i]-ru[i]==1) s=i;
        else if(ru[i]-chu[i]==1) t=i;
    }
    int cnt=ru[t];
    for(int i=1;i<=n;++i){
        if(a[i][0]==s&&(a[i][m[i]]!=t||cnt!=1)){
            st=i;
            break;
        }
    }
    vis[st]=1;
    now[++sum]=a[st];
    dfs(st,1);
    if(!flag){
        cout<<"***"<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i){
        cout<<ans[i]<<".\n"[i==n];
    }
    return 0;
}