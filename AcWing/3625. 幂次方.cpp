#include<iostream>
using namespace std;
const int P=233333;
long long x,n;
int main()
{
    cin>>x>>n;
    int b=1;
    while(n){
        if(n&1) b=b*x%P;
        n>>=1;
        x=x*x%P;
    }
    cout<<b<<endl;
    return 0;
}