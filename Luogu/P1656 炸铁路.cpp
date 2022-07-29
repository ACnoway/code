#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int p[200];
struct node
{
    int x,y;
    bool operator <(const node s)const{
        if(x==s.x) return y<s.y;
        return x<s.x;
    }
}a[5003];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>a[i].x>>a[i].y;
        if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
    }
    sort(a,a+m);
    int cnt=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<=n;++j){
            p[j]=j;
        }
        for(int j=0;j<m;++j){
            if(i==j) continue;
            p[find(a[j].x)]=find(a[j].y);
        }
        cnt=0;
        for(int j=1;j<=n;++j){
            if(p[j]==j) cnt++;
            if(cnt==2) break;
        }
        if(cnt==2) cout<<a[i].x<<' '<<a[i].y<<endl;
    }
    return 0;
}