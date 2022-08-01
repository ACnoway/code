#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct oil{
    double dis,pr;
}a[10];
bool cmp(oil a,oil b){
    if(a.dis==b.dis) return a.pr<b.pr;
    return a.dis<b.dis;
}
double d,c,dy,now;
int n;
double acost(int from,int to){
    return (a[to].dis-a[from].dis)/dy*a[from].pr;
}
int main()
{
    cin>>d>>c>>dy;
    cin>>a[0].pr;
    a[0].dis=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].dis>>a[i].pr;
    }
    if(n==0){
        if(c*dy<d) cout<<"No Solution"<<endl;
        else printf("%.2lf",d/dy*a[0].pr);
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    double ans=0;
    for(int i=0;i<=n;++i){
        if(c*dy<a[i+1].dis-a[i].dis) cout<<"No Solution"<<endl;
        
    }
    return 0;
}