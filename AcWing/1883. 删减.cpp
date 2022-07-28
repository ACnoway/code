#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    string s,t,st;
    cin>>s>>t>>st;
    for(auto c:s){
        st+=c;
        while(st.size()>=t.size()&&st.substr(st.size()-t.size())==t)
            st.erase(st.end()-t.size(),st.end());
    }
    cout<<st<<endl;
    return 0;
}