#include <iostream>
using namespace std;
int a,b,c,d,ans;
bool e[150];
int main(){
    cin>>a>>b>>c>>d;
    for(int i=a;i<b;++i) e[i]=true;
    for(int i=c;i<d;++i) e[i]=true;
    for(int i=0;i<=110;++i){
        ans+=e[i];
    }
    cout<<ans;
}