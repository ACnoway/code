#include<iostream>
#include<cctype>
using namespace std;
string a[30][10];
string s;
int main()
{
    for(int i=0;i<26;++i){
        for(int j=0;j<7;++j) cin>>a[i][j];
    }
    cin>>s;
    int w=0,i=0;
    while(w<s.size()){
        for(;w<s.size();++w){
            if(s[w]<'A'||s[w]>'Z') break;
        }
        if(i==w){
            i=++w;
            continue;
        }
        for(int j=0;j<7;++j){
            for(int t=i;t<w;++t){
                cout<<a[s[t]-'A'][j];
                if(t+1<w) putchar(' ');
            }
            cout<<endl;
        }
        if(w+1<s.size()) cout<<endl;
        w++;
        i=w;
    }
    return 0;
}