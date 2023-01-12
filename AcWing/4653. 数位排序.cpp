#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m,z;
struct node{
    int x,y;
    node(){y=0;}
}t[1000006];
bool cmp(node a,node b){
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        t[i].x=i;
        z=i;
        while(z){
            t[i].y+=z%10;
            z/=10;
        }
    }
    sort(t+1,t+n+1,cmp);
    cout<<t[m].x<<endl;
    return 0;
}