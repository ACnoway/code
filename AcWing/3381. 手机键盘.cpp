#include<iostream>
using namespace std;
int al[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int ac[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main()
{
    string a;
    int ans=0;
    while(cin>>a){
        ans=0;
        for(int i=0;i<a.size();++i){
            if(i>0&&al[a[i]-'a']==al[a[i-1]-'a']) ans+=2;
            ans+=ac[a[i]-'a'];
        }
        cout<<ans<<endl;
    }
    return 0;
}