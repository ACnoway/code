#include<iostream>
using namespace std;
int main()
{
    int a,b;
    string n;
    cin>>a>>n>>b;
    int x=0;
    for(int i=0;i<n.size();++i){
        if(isdigit(n[i])) x=x*a+n[i]-'0';
        else if(isupper(n[i])) x=x*a+n[i]-'A'+10;
        else x=x*a+n[i]-'a'+10;
    }
    string ans;
    while(x){
        int d=x%b;
        ans=char(d<10?d+'0':d+'A'-10)+ans;
        x/=b;
    }
    cout<<ans<<endl;
    return 0;
}