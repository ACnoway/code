#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
char wt(){
    return getchar();
}
int main()
{
    for(int i=1;i<=2000;++i){
        debug(i);
        system("a1test.exe");
        double st=clock();
        system("std.exe");
        double en=clock();
        system("bl.exe");
        if(system("fc wastd.out wabl.out")) cout<<"WA on test No."<<i<<endl,wt();
        else cout<<"AC! Time:"<<en-st<<endl;
    }
    return 0;
}