#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n=100000;
    cout<<n<<endl;
    for(int i=1;i<=n;++i){
        cout<<((rand()+rand())*100)%1000000000+1<<' '<<((rand()+rand())*100)%1000000000+1<<endl;
    }
    return 0;
}