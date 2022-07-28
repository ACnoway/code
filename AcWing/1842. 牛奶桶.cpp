#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int x,y,m;
    cin>>x>>y>>m;
    int temp=m;
    while(m>=x){
        if(m>=x&&m<y) m%=x;
        else if(m%x<m%y) m-=x;
        else m-=y;
    }
    cout<<temp-m;
    return 0;
}