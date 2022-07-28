#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c;
    int aa[10];
    for(int i=0;i<=6;++i) cin>>aa[i];
    sort(a,a+7);
    cout<<aa[0]<<' '<<aa[1]<<' '<<aa[6]-aa[0]-aa[1]<<endl;
    return 0;
}