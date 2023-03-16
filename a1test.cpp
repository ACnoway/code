#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    string s="";
    cin>>a;
    while(a){
        s=char((a&1)+'0')+s;
        a>>=1;
    }
    cout<<s<<endl;
    return 0;
}