#include <iostream>
using namespace std;
int a[210],b[210];
int vs[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main()
{
    int n,na,nb;
    int aa=0,ab=0;
    cin>>n>>na>>nb;
    for(int i=0;i<na;++i) cin>>a[i];
    for(int i=0;i<nb;++i) cin>>b[i];
    for(int i=0;i<n;++i){
        aa+=vs[a[i%na]][b[i%nb]];
        ab+=vs[b[i%nb]][a[i%na]];
    }
    cout<<aa<<' '<<ab<<endl;
    return 0;
}