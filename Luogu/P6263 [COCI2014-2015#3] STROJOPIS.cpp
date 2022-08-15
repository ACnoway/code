#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
map<char,int> m;
int a[10];
string s;
int main()
{
    m['1']=0;m['Q']=0;m['A']=0;m['Z']=0;
    m['2']=1;m['W']=1;m['S']=1;m['X']=1;
    m['3']=2;m['E']=2;m['D']=2;m['C']=2;
    m['4']=3;m['R']=3;m['F']=3;m['V']=3;
    m['5']=3;m['T']=3;m['G']=3;m['B']=3;
    m['6']=4;m['Y']=4;m['H']=4;m['N']=4;
    m['7']=4;m['U']=4;m['J']=4;m['M']=4;
    m['8']=5;m['I']=5;m['K']=5;m[',']=5;
    m['9']=6;m['O']=6;m['L']=6;m['.']=6;
    m['0']=7;m['P']=7;m[';']=7;m['/']=7;
    m['-']=7;m['[']=7;m['\'']=7;m['=']=7;m[']']=7;
    cin>>s;
    for(int i=0;i<s.size();++i){
        a[m[s[i]]]++;
    }
    for(int i=0;i<8;++i) cout<<a[i]<<endl;
    return 0;
}