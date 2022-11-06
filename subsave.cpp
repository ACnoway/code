#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
string names[100005];
int main(int num,char**ss){
    string u,pth,name,s;
    s="@echo off";
    system(s.c_str());
    for(int i=0;i<num;++i){
        names[i]="";
        for(int j=0;ss[i][j]!='\0';++j){
            names[i]+=ss[i][j];
        }
    }
    for(int i=1;i<num;++i){
        bool pd=true;
        u="";
        int j;
        j=names[i].size()-1;
        while(names[i][j]!='\\')--j;
        for(++j;true;++j){
            if(names[i][j]<'0'||names[i][j]>'9'){
                if(pd){
                    u+=names[i][j];
                    continue;
                }
                break;
            }
            u+=names[i][j];
            pd=false;
        }
        pth=name="";
        j=names[i].size()-1;
        while(names[i][j]!='\\')--j;
        for(;j>=0;--j){
            pth=names[i][j]+pth;
        }
        j=names[i].size()-1;
        while(names[i][j]!='\\')--j;
        for(++j;j<(int)names[i].size();++j){
            name+=names[i][j];
        }
        s="if not exist \""+pth+u+"\"  ( md \""+pth+u+"\")";
        system(s.c_str());
        s="move "+pth+name+" "+pth+u+"\\"+name;
        system(s.c_str());
    }
    system("pause");
    return 0;
}
