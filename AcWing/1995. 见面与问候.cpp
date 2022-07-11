#include <iostream>
using namespace std;
int b[1000006],e[1000006];
int main()
{
    int n,m,cb=0,ce=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int d;
        char p;
        cin>>d>>p;
        for(int j=1;j<=d;++j){
            if(p=='L') b[++cb]=b[cb-1]-1;
            else b[++cb]=b[cb-1]+1;
        }
    }
    for(int i=1;i<=n;++i){
        int d;
        char p;
        cin>>d>>p;
        for(int j=1;j<=d;++j){
            if(p=='L') e[++ce]=e[ce-1]-1;
            else e[++ce]=e[ce-1]+1;
        }
    }
    
    return 0;
}