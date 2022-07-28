#include<iostream>
using namespace std;
int n,ans;
int a[15];
bool l[15],d1[30],d2[30];
void print(){
    for(int i=1;i<=n;++i){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
void work(int x){
    for(int i=1;i<=n;++i){
        if(!l[i]&&!d1[x-i+n-1]&&!d2[x+i]){
            l[i]=1;
            d1[x-i+n-1]=1;
            d2[x+i]=1;
            a[x]=i;
            if(x==n){
                if(ans<3) print();
                ans++;
            }
            else work(x+1);
            l[i]=0;
            d1[x-i+n-1]=0;
            d2[x+i]=0;
        }
    }

}
int main()
{
    cin>>n;
    work(1);
    cout<<ans<<endl;
    return 0;
}