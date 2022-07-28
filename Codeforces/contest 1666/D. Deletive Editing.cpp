#include <iostream>
#include <cstdio>
using namespace std;
int n,st;
int main()
{
    cin>>n;
    while(n--){
        string a,b;
        cout<<"------------------------------"<<endl;
        cin>>a>>b;
        cout<<"------------------------------"<<endl;
        if(a==b){
            cout<<"YES"<<endl;
            continue;
        }
        bool flag;
        while(a.size()){
            for(int i=0;i<b.size();++i){
                int p=a.find(b[i]);
                flag=false;
                if(p!=-1){
                    flag=true;
                    a=a.substr(p+1,a.size()-p);
                    p=a.find(b[i]);
                    cout<<a<<endl;
                }
                if(!flag){
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if(!flag) continue;
        else cout<<"YES"<<endl;
    }
    return 0;
}