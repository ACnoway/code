#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long x,y,z;
        cin>>x>>y>>z;
        if(z<x){
            cout<<"Merry"<<endl;
            continue;
        }
        if((z-x+z-1)*x/2+(z-x)<y){
            cout<<"Merry"<<endl;
            continue;
        }
        cout<<"Renko"<<endl;
    }
    return 0;
}