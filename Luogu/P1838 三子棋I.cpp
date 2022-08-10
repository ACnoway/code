#include<iostream>
using namespace std;
int hang[10]={0,
    1,1,1,
    2,2,2,
    3,3,3},
    lie[10]={0,
    4,5,6,
    4,5,6,
    4,5,6},
    dj1[10]={0,
    7,0,0,
    0,7,0,
    0,0,7},
    dj2[10]={0,
    0,0,8,
    0,8,0,
    8,0,0};
int x[2][9];
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();++i){
        x[i&1][hang[s[i]-'0']]++;
        x[i&1][lie[s[i]-'0']]++;
        x[i&1][dj1[s[i]-'0']]++;
        x[i&1][dj2[s[i]-'0']]++;
    }
    for(int i=1;i<=8;++i){
        if(x[0][i]==3){cout<<"xiaoa wins.\n";return 0;}
        else if(x[1][i]==3){cout<<"uim wins.\n";return 0;}
    }
    cout<<"drew."<<endl;
    return 0;
}