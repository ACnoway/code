#include <iostream>
#include <cstdio>
using namespace std;
const int P=1000000007;
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,k;
int a[503];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    cin>>s;
    int temp=0,ans=0;
    for(int i=0;i<n;++i){
        a[i]=a[i-1];
        if(s[i]=='?') a[i]++;
    }
    for(int i=0;i<n;++i){
        
    }
    return 0;
}