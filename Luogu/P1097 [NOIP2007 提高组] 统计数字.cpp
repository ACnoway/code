#include <iostream>
#include <map>
#include <set>
using namespace std;
map <int,int> m;
set<int> s;
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        s.insert(x);
        m[x]++;
    }
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<' '<<m[*i]<<endl;
    }
    return 0;
}