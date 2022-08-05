#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int p[3];
    cin>>p[0]>>p[1]>>p[2];
    for(int i=0;i<3;++i){
        if((p[i]%(a+b))<=a&&(p[i]%(c+d))<=c) cout<<"both"<<endl;
        else if((p[i]%(a+b))<=a||(p[i]%(c+d))<=c) cout<<"one"<<endl;
        else cout<<"none"<<endl;
    }
    return 0;
}