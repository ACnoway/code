#include<iostream>
#include<algorithm>
using namespace std;
char c[27];
int main()
{
    for(int i=0;i<26;++i) c[i]=i+'a';
    int n;
    cin>>n;
    cout<<'a';
    for(int i=1;i<n;++i) cout<<'b';
    return 0;
}