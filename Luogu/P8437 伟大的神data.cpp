#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=10;
    int m=rand()%n+4;
    while(m&1) m=rand()%n+4;
    int k=2;
    cout<<n<<' '<<m<<' '<<k<<endl;
    return 0;
}