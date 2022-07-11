#include <iostream>
using namespace std;
string a,b;
void work(string a,string b){
    if(b.size()){
        cout<<b[b.size()-1];
        int p=a.find(b[b.size()-1]);
        work(a.substr(0,p),b.substr(0,p));
        work(a.substr(p+1),b.substr(p,a.size()-p-1));
    }
}
int main()
{
    cin>>a>>b;
    work(a,b);
    return 0;
}