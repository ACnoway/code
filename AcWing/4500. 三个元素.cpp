#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int v,p;
}a[4000];
int n;
bool cmp(node a,node b){
    return a.v<b.v;
}
int b[5];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].v,a[i].p=i;
    sort(a+1,a+1+n,cmp);
    int cnt=0;
    for(int i=1;cnt<3&&i<=n;++i){
        if(a[i].v!=a[i-1].v) b[cnt++]=a[i].p;
    }
    if(cnt<3){
        cout<<"-1 -1 -1"<<endl;
    }
    else cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<endl;
    return 0;
}