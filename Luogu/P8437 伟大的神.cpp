#include<iostream>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(k!=2){
        for(int i=0;i<m;++i){
            if(i&1) cout<<'r';
            else cout<<'l';
        }
        int c=0;
        for(int i=m;i<n;++i){
            if(c<k) c++,cout<<'l';
            else c=0,cout<<'r';
        }
    }
    else{
        int d=m%4;
        for(int i=0;i<m/4;++i){
            cout<<"llrr";
        }
        for(int i=0;i<d;++i){
            if(i&1) cout<<'r';
            else cout<<'l';
        }
        int c=0;
        for(int i=m;i<n;++i){
            if(c<2) c++,cout<<'l';
            else if(c==2) c++,cout<<'r';
            if(c==3) c=0;
        }
    }
    cout<<endl;
    return 0;
}