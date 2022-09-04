#include<iostream>
using namespace std;
int n,ans;
string s;
int main()
{
    cin>>n;
    getchar();
    int flag;
    for(int i=0;i<n;++i){
        flag=0;
        getline(cin,s);
        for(int j=0;j<s.size();++j){
            if(s[j]!=' '&&s[j]!='\n'&&s[j]!='\r'&&flag==1){
                flag=2;
                break;
            }
            if(s[j]=='#'&&s[j+1]==' ') flag=1;
            if(s[j]!=' '&&flag!=1) break;
        }
        if(flag==2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}