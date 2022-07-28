#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int ans=0;
    for(int i=1;i<=8;++i){
        char c;
        c=getchar();
        ans+=(c-'0');
    }
    cout<<ans;
    return 0;
}