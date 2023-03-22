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
int n,he,chang;
int tong[30];
struct node{
    string s;
    int id;
    bool operator <(const node &x)const{
        return s<=x.s;
    }
}a[500005],ans[20];
bool vis[20];
bool check(){
    //return 0;
    string tmp="";
    for(int i=1;i<=n;++i) tmp+=ans[i].s;
    for(int i=0;i<tmp.size();i+=2){
        if(tmp[i]!=tmp[i+1]) return 0;
    }
    return 1;
}
void dfs(int x){
    if(x>n){
        if(check()){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;++i){
                cout<<ans[i].id<<' ';
            }
            exit(0);
        }
        return;
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            vis[i]=1;
            ans[i].s=a[x].s;
            ans[i].id=a[x].id;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].s;
        a[i].id=i;
        he+=a[i].s.size();
        chang=max(chang,(int)a[i].s.size());
    }
    if(he&1){
        cout<<"NO"<<endl;
        return 0;
    }
    if(chang==1){
        sort(a+1,a+n+1);
        for(int i=1;i<=n;++i){
            ++tong[a[i].s[0]-'a'];
        }
        bool flag=1;
        for(int i=0;i<26;++i){
            if(tong[i]&1){
                flag=0;
                break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
            return 0;
        }
        for(int i=1;i<=n;++i){
            cout<<a[i].id<<' ';
        }
        putchar('\n');
        return 0;
    }
    dfs(1);
    cout<<"NO"<<endl;
    return 0;
}