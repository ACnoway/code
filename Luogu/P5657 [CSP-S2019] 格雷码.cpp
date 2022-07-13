#include<iostream>
using namespace std;
int main()
{
    int n;
    unsigned long long k;
    cin>>n>>k;
    k^=k>>1;
    while(~--n) cout<<(k>>n&1);
    return 0;
}