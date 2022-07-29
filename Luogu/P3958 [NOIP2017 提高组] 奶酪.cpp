#include<iostream>
#define ll long long
using namespace std;
const int N=100005;
int p[1001];
ll x[N],y[N],z[N];
int f1[N],f2[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
ll dis(ll x,ll y,ll z,ll x1,ll y1,ll z1){
    return (x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1);
}
int main()
{
    int t;
    cin>>t;
    int n,h;
    ll r;
    for(int i=1;i<=t;++i){
        cin>>n>>h>>r;
        int c1=0,c2=0;
        for(int j=1;j<=n;++j){
            p[j]=j;
        }
        for(int j=1;j<=n;++j){
            cin>>x[j]>>y[j]>>z[j];
            if(z[j]+r>=h) f1[++c1]=j;
            if(z[j]-r<=0) f2[++c2]=j;
            for(int k=1;k<j;++k){
                if((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k])>4*r*r) continue;
                if(dis(x[j],y[j],z[j],x[k],y[k],z[k])<=4*r*r){
                    int a1=find(j),a2=find(k);
                    if(a1!=a2) p[a1]=a2;
                }
            }
        }
        int s=0;
        for(int j=1;j<=c1;++j){
            for(int k=1;k<=c2;++k){
                if(find(f1[j])==find(f2[k])){
                    s=1;
                    break;
                }
            }
            if(s) break;
        }
        if(s) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
