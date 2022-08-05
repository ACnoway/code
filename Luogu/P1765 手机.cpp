#include<iostream>
using namespace std;
int ac[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main()
{
    string a;
    int ans=0;
    getline(cin,a);
    ans=0;
    for(int i=0;i<a.size();++i){
        if(a[i]==' '){
            ans+=1;
            continue;
        }
        if(a[i]=='\n'||a[i]=='\r') break;
        ans+=ac[a[i]-'a'];
    }
    cout<<ans<<endl;
    return 0;
}