#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double a,b;
int main()
{
    cin>>a>>b;
    printf("%.16lf",floor(b/a)/b);
    return 0;
}