#include <iostream>
using namespace std;
int n;
bool isClose(int a, int b)
{
    if(abs(a-b)<=2 || abs(a-b)>=n-2)
        return true;
    return false;
}

bool check(int n1, int n2, int n3, int c1, int c2, int c3)
{
    return isClose(n1, c1) && isClose(n2, c2) && isClose(n3, c3);
}
int main()
{
    int ans=0;
    int a[5],b[5],c[5];
    bool f1=true,f2=true;
    cin>>n;
    for(int i=0;i<3;++i) cin>>a[i];
    for(int i=0;i<3;++i) cin>>b[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                c[0]=i;
                c[1]=j;
                c[2]=k;
                if(check(c[0],c[1],c[2],a[0],a[1],a[2])||check(c[0],c[1],c[2],b[0],b[1],b[2])) ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}