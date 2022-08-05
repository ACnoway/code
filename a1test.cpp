#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int f,n,k;
int e[N],ne[N];
void work(string x){
    if(isdigit(x[0])){
        int a=0;
        for(int i=0;i<x.size();++i){
            a=a*10+x[i]-'0';
        }
        cout<<(char)a<<endl;
    }
    else cout<<(int)x[0];
}
int main()
{
    string s;
    cin>>s;
    work(s);
    return 0;
}