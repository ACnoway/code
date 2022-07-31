#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<string,bool> xy;
int n,m,cnt;
string come[100005];
int main()
{
    cin>>n;
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        xy[s]=1;
    }
    cin>>m;
    string ax="",ac="";
    for(int i=0;i<m;++i){
        cin>>s;
        if(xy[s]){
            cnt++;
            if(ax.size()){
                if(ax.substr(6,8)<s.substr(6,8)) ax=s;
            }
            else ax=s;
        }
        if(ac.size()){
            if(ac.substr(6,8)<s.substr(6,8)) ac=s;
        }
        else ac=s;
    }
    cout<<cnt<<endl;
    if(cnt) cout<<ax;
    else cout<<ac;
    return 0;
}