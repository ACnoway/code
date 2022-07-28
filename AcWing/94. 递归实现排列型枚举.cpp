#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[50];
bool v[50];
void work(int x){
    if(x>n){
        for(int i=1;i<=n;++i){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;++i){
        if(v[i]) continue;
        v[i]=true;
        a[x]=i;
        work(x+1);
        a[x]=0;
        v[i]=false;
    }
}
int main()
{
    cin>>n;
    work(1);
    return 0;
}