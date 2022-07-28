#include<iostream>
#include<unordered_map>
#define int long long
using namespace std;
const int N=100005;
unordered_map<int,int> m;
int p[N];
int a[N][3];
int b[N][2];
int t,n;
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
signed main()
{
    int ca,cb;
    bool flag;
    cin>>t;
    while(t--){
        cin>>n;
        ca=0;cb=0;
        m.clear();
        for(int i=0;i<N;++i) p[i]=i;
        for(int i=1;i<=n;++i){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(!m[a[i][0]]) m[a[i][0]]=++ca;
            if(!m[a[i][1]]) m[a[i][1]]=++ca;
            if(a[i][2]==1){
                p[find(m[a[i][0]])]=find(m[a[i][1]]);
            }
            else{
                b[++cb][0]=a[i][0];
                b[cb][1]=a[i][1];
            }
        }
        flag=true;
        for(int i=1;i<=cb;++i){
            if(find(m[b[i][0]])==find(m[b[i][1]])){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}