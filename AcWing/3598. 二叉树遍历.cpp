#include<iostream>
using namespace std;
void hou(string qq,string zz){
    if(zz.size()){
        char r=qq[0];
        int k=zz.find(r);
        hou(qq.substr(1,k),zz.substr(0,k));
        hou(qq.substr(k+1),zz.substr(k+1));
        putchar(r);
    }
}
int main()
{
    string q,z;
    while(cin>>q>>z){
        hou(q,z);
        putchar('\n');
    }
    return 0;
}