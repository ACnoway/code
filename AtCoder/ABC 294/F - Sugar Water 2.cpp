#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
int n,m,k;
struct node{
    double x,y,nong;
    bool operator <(const node &o)const{
        return nong>o.nong;
    }
}a[50004],b[50004];
double calc(int x,int y){
    return 100*(a[1].x+b[1].x)/(a[1].x+b[1].x+a[1].y+b[1].y);
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i].x>>a[i].y;
        a[i].nong=100*a[i].x/(a[i].x+a[i].y);
    }
    for(int i=1;i<=m;++i){
        cin>>b[i].x>>b[i].y;
        b[i].nong=100*a[i].x/(a[i].x+a[i].y);
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int cnt=1,ai=1,aj=2,bi=2,bj=1;
    double ans=100*(a[1].x+b[1].x)/(a[1].x+b[1].x+a[1].y+b[1].y);
    while(cnt<k){
        if(calc(ai,aj)>calc(bi,bj)){
            cnt++;
            ans=calc(ai,aj);
            aj++;
        }
        else{
            cnt++;
            ans=calc(bi,bj);
            bi++;
        }
    }
    printf("%.11lf\n",ans);
    return 0;
}