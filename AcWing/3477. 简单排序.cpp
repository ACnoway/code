#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    set<int> s;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        s.insert(x);
    }
    for(auto i:s){
        cout<<i<<' ';
    }
    return 0;
}