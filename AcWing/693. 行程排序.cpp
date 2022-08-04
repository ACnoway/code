#include<iostream>
#include<unordered_map>
using namespace std;
int t,n;
unordered_map<string,string> ne;
unordered_map<string,int> c;
int main()
{
    cin>>t;
    string a,b,h;
    for(int tt=1;tt<=t;++tt){
        ne.clear();
        c.clear();
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a>>b;
            c[a]++;
            c[b]=2;
            ne[a]=b;
        }
        for(unordered_map<string,int>::iterator i=c.begin();i!=c.end();i++){
            if(i->second==1){
                h=i->first;
                break;
            }
        }
        //cout<<"h:"<<h<<endl;
        cout<<"Case #"<<tt<<": ";
        for(string i=h;ne[i]!="";i=ne[i]){
            cout<<i<<'-'<<ne[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}