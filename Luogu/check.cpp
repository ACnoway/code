#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
ifstream user,fstd;
ofstream report;
int main()
{
    user.open("P7911.txt");
    fstd.open("std.txt");
    report.open("report.txt");
    string u,s;
    int cnt=1;
    while(user>>u){
        fstd>>s;
        if(u!=s) report<<cnt<<" user:"<<u<<" std:"<<s<<endl;
        cnt++;
    }
    user.close();
    fstd.close();
    report.close();
    return 0;
}