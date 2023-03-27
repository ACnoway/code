#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<endl<<#x<<'='<<x<<endl
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
const int N=500005;
int T,n,ans,now,top;
int a[N],Ans[N],st[N];
struct node{
    int v,p;
    bool operator <(const node &x)const{
        return v<x.v;
    }
}b[N];
vector<int> e[N];
void dfs(int x,int die,int da){
    for(int v:e[x]){
        if(v==die) continue;
        if(a[v]>=da){
            ++ans;
        }
        dfs(v,x,max(da,a[v]));
    }
}
int main()
{
    freopen("ltc.in","r",stdin);
    freopen("ltc.out","w",stdout);
    bool flag1,flag2;
    T=read();
    while(T--){
        n=read();
        for(int i=0;i<=n+1;++i) Ans[i]=1,e[i].clear();
        flag1=flag2=1;
        for(int i=1;i<n;++i){
            int u=read(),v=read();
            if(u!=1||v!=i+1) flag2=0;
            if(u!=i||v!=i+1) flag1=0;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;++i) a[i]=read();
        if(flag1){
            top=0;
            for(int i=1;i<=n;++i){
                while(top&&st[top]<a[i]) --top;
                Ans[i]+=top;
                st[++top]=a[i];
            }
            top=0;
            for(int i=n;i;--i){
                while(top&&st[top]<a[i]) --top;
                Ans[i]+=top;
                st[++top]=a[i];
            }
            for(int i=1;i<=n;++i) printf("%d ",Ans[i]);
            putchar('\n');
            continue;
        }
        if(flag2){
            int cnt=0,now1;
            for(int i=1;i<=n;++i){
                b[i].v=a[i];
                b[i].p=i;
            }
            sort(b+1,b+1+n);
            for(int i=n;i;--i){
                if(b[i].p!=1) cnt++;
                else{
                    now1=i;
                    break;
                }
            }
            for(int i=1;i<=n;++i){
                if(i<=now1) Ans[b[i].p]+=cnt+(i!=now1);
                else{
                    Ans[b[i].p]+=n-i;
                }
            }
            for(int i=1;i<=n;++i) printf("%d ",Ans[i]);
            putchar('\n');
            continue;
        }
        for(int i=1;i<=n;++i){
            ans=1;
            dfs(i,0,a[i]);
            printf("%d ",ans);
        }
        putchar('\n');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}