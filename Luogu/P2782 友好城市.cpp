#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int a,b;
}t[200005];
bool cmp(node a,node b){
    return a.a<b.a;
}
int f[200005];
int n,len;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i].a>>t[i].b;
    }
    sort(t+1,t+n+1,cmp);
    f[++len]=t[1].a;
    for(int i=2;i<=n;++i){
        int d=upper_bound(f+1,f+len+1,t[i].a)-f;
        f[d]=t[i].a;
        if(d>len) ++len;
    }
    cout<<len<<endl;
    return 0;
}