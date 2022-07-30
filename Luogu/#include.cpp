#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> ss;
    int s=1,t=rand()%10+1,n,x,y;
    cout<<s<<endl;
    cout<<t<<endl;
    while(t--){
        srand(time(0));
        n=rand()%100+1;
        x=rand()%n;
        y=n-x-1;
        cout<<n<<' '<<x<<' '<<y<<endl;
        while(ss.size()<n){
            ss.insert(rand()%n);
        }
        for(auto i:ss) cout<<i<<' ';
        cout<<endl;
        ss.clear();
    }
    return 0;
}