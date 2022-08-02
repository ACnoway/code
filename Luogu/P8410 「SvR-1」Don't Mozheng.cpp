#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,a,b,ans=0;
    cin>>n>>a>>b;
    getchar();
    for(int i=1;i<=n;++i){
        char temp[60],s[60];
        scanf("%[^\n]%[^\n]",temp,s);
        //cout<<s<<endl;
        if(s=="/oh") ans+=a;
        else if(s=="/hsh") ans+=b;
    }
    cout<<ans<<endl;
    return 0;
}