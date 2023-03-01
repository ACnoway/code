#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=1;i<=100;++i){
        if(i%3==0){
            putchar('F');
        }
        if(i%5==0)
            putchar('B');
    }
    return 0;
}