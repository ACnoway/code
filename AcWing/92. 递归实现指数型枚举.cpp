#include <iostream>
#include <cstdio>
using namespace std;
int n,cnt;
int a[20];
void work(int x){
    if(x>n){
        for(int i=1;i<=n&&i<=cnt;++i){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        return;
    }
    //不选x
    work(x+1);
    //选x
    a[++cnt]=x;
    work(x+1);
    //回溯
    cnt--;
    return;
}
int main()
{
    cin>>n;
    cout<<endl;
    work(1);
    return 0;
}