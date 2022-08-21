#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int ans=0;
    cin>>a>>b;
    if(a>b) swap(a,b);
    //按照常理来说应该用while的
    //不过用b也一样，因为a和b的差不可能超过b
    //也就是最多最多走b步（其实b/2也行）
    for(int i=0;i<=b;++i){
        a++;
        ans+=i+1;
        if(a==b){
            cout<<ans<<endl;
            return 0;
        }
        b--;
        ans+=i+1;
        if(a==b){
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}