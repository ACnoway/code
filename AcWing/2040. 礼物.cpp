#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int p,s;
    bool operator <(const node &x)const{
        if(p+s==x.p+x.s) return p>x.p;
        return p+s<x.p+x.s;
    }
}a[1003];
int n,b,ans,now;
int main()
{
    cin>>n>>b;
    for(int i=0;i<n;++i) cin>>a[i].p>>a[i].s;
    sort(a,a+n);
    bool used=false;
    int i;
    for(i=0;i<n;++i){
        now+=a[i].p+a[i].s;
        if(now>b&&used) break;
        else if(now>b){
            used=true;
            now-=a[i].p;
            now+=(a[i].p>>1);
            if(now>b) break;
        }
    }
    cout<<i<<endl;
    return 0;
}