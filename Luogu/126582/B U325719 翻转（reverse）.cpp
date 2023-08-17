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
const int N=500005;
string s;
int k;
int a[N],p[N];
typedef pair<int,int> pii;
pii b[N];
int main()
{
    cin>>s;
    cin>>k;
    for(int i=1;i<=k;++i){
        cin>>a[i];
        b[i].first=a[i-1];
        b[i].second=a[i];
    }
    int d=-2;
    p[1]=k;
    for(int i=2;i<=k;++i){
        p[i]=p[i-1]+d;
        if(p[i]<=1){
            p[i]=0;
            d=2;
        }
    }
    p[(k+1)/2]=1;
    int st,en;
    for(int i=1;i<=k;++i){
        st=b[p[i]].first;
        en=b[p[i]].second-1;
        if((k-p[i])&1){
            //翻转成了原样
            for(int j=st;j<=en;++j){
                putchar(s[j]);
            }
        }
        else{
            //翻转
            for(int j=en;j>=st;--j){
                putchar(s[j]);
            }
        }
    }
    for(int i=a[k];i<s.size();++i) putchar(s[i]);
    cout<<endl;
    return 0;
}