#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n;
struct node
{
    char name[20];
    int v;
    node(){v=0;}
}a[8];
char cow[8][20]={"Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta"};
bool cmp(node a,node b){
    return a.v<b.v;
}
int main()
{
    cin>>n;
    for(int i=0;i<7;++i){
        for(int j=0;j<strlen(cow[i]);++j){
            a[i].name[j]=cow[i][j];
        }
    }
    for(int i=0;i<n;++i){
        char c[20];
        int va;
        cin>>c>>va;
        for(int j=0;j<7;++j){
            if(a[j].name[0]==c[0]){
                a[j].v+=va;
                break;
            }
        }
    }
    sort(a,a+7,cmp);
    for(int i=1;i<7;++i){
        if(a[i].v>a[i-1].v){
            if(a[i+1].v!=a[i].v){
                cout<<a[i].name<<endl;
                return 0;
            }
            else if(a[i+1].v==a[i].v){
                cout<<"Tie"<<endl;
                return 0;
            }
        }
    }
    cout<<"Tie"<<endl;
    return 0;
}