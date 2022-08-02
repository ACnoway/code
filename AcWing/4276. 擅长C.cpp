#include<iostream>
#include<cctype>
using namespace std;
string a[30][10];
string o[303];
string s="";
int main()
{
    for(int i=0;i<26;++i){
        for(int j=0;j<7;++j) cin>>a[i][j];
    }
    getchar();
    string in;
    while(getline(cin,in)) s+=in;
    for(int i=0;i<303;++i) o[i]="";
    int n=0;
    for(int i=0;i<s.size();++i){
        if((s[i]<'A'||s[i]>'Z')&&o[n]!="") n++;
        else if(s[i]>='A'&&s[i]<='Z') o[n]+=s[i];
    }
    if(s[s.size()-1]>='A'&&s[s.size()-1]<='Z') n++;
    string tmp="";
    for(int i=0;i<n;++i){
        for(int j=0;j<7;++j){
            tmp="";
            for(int k=0;k<o[i].size();++k){
                tmp+=a[o[i][k]-'A'][j];
                if(k<o[i].size()-1) tmp+=' ';
            }
            cout<<tmp<<endl;
        }
        if(i<n-1) cout<<endl;
    }
    return 0;
}