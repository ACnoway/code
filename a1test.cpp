#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("P1156.in","w",stdout);
    srand(time(0));
    int d=rand()%99+2,g=rand()%100+1;
    cout<<d<<' '<<g<<endl;
    for(int i=1;i<=g;++i){
        cout<<rand()%1000+1<<' '<<rand()%30+1<<' '<<rand()%25<<endl;
    }
    return 0;
}