#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int p[2000];
struct node{
    int x,y,t;
    bool operator <(const node x)const{
        return t<x.t;
    }
}a[100005];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(p[i]==i) cnt++;
        if(cnt==2) return 0;
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;++i) p[i]=i;
    int x,y,t,ma=0;
    for(int i=0;i<m;++i){
        cin>>a[i].x>>a[i].y>>a[i].t;
    }
    sort(a,a+m);
    int ans=-1;
    for(int i=0;i<m;++i){
        p[find(a[i].x)]=find(a[i].y);
        if(check()){
            ans=a[i].t;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}