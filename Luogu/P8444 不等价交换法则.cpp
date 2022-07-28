#include<iostream>
#include<algorithm>
using namespace std;
int n,w;
int a[1000006];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    cin>>w;
    sort(a,a+n);
    int cnt=0,p;
    for(p=-1;p<n;++p){
        if(p+1>=n||a[p+1]>w) break;
    }
    if(p==-1){
        cout<<"0"<<endl;
        return 0;
    }
    w=a[p];
    for(;cnt<p;++cnt){
        if(w>=a[cnt]) w-=a[cnt];
        else break;
    }
    cout<<(cnt?cnt:1);
    return 0;
}