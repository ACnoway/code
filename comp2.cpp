#include<iostream>
#include<unordered_map>
#define int long long
using namespace std;
const int N=400005;
unordered_map<int,int> m;
int p[N];
int no[N][2];
int t,n;
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("237.txt", "r", stdin);
    #endif
    int a,b,e,ca,cb;
    bool flag;
    cin>>t;
    while(t--){
        cin>>n;
        ca=0;cb=0;
        m.clear();
        for(int i=0;i<=2*n;++i) p[i]=i;
        for(int i=1;i<=n;++i){
            cin>>a>>b>>e;
            if(m[a]==0) m[a]=++ca;
            if(m[b]==0) m[b]=++ca;
            if(e){
                p[find(m[a])]=find(m[b]);
            }
            else{
                no[++cb][0]=a;
                no[cb][1]=b;
            }
        }
        flag=true;
        for(int i=1;i<=cb;++i){
            if(find(m[no[i][0]])==find(m[no[i][1]])){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}