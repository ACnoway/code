#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n=10;
    cout<<n<<endl;
    for(int i=1;i<=n;++i) cout<<(rand()%2?1:-1)*rand()%100<<' ';
    return 0;
}