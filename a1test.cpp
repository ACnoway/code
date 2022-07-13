#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 20;

bool check(int x){
    if(x==1) return 0;
    if(x==2) return 1;
    if(x%2==0) return 0;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return 0;
    }
    return 1;
}

int main()
{
    cout<<(check(22)&&check(22-6))<<endl<<(check(22)&&check(22+6))<<endl;
    return 0;
}