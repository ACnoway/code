#include<iostream>
using namespace std;
string days[10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int mo[13]={0,0,0,0,18,31,30,31,31,30,31,30,31};
int main()
{
    int m,d;
    cin>>m>>d;
    if(m==4){
        cout<<days[(d-12+4)%7]<<endl;
        return 0;
    }
    int ans=0;
    for(int i=4;i<m;++i){
        ans+=mo[i];
    }
    ans+=d;
    cout<<days[(ans%7+4)%7]<<endl;
    return 0;
}