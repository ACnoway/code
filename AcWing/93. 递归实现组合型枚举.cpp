#include <iostream>
#include <cstdio>
using namespace std;
int cnt,n,m;
int a[50];
void work(int x){
    if(cnt>m||cnt+(n-x+1)<m) return;
    if(cnt==m){
        for(int i=1;i<=cnt;++i){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        return;
    }
    a[++cnt]=x;
    work(x+1);
    cnt--;
    work(x+1);
    return;
}
int main()
{
    cin>>n>>m;
    work(1);
    return 0;
}
