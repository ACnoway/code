#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int p,xa,ya,xb,yb;
int main()
{
    cin>>p>>xa>>ya>>xb>>yb;
    switch(p){
        case 1:{
            if(xa==xb||ya==yb) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            break;
        }
        case 2:{
            cout<<"No"<<endl;
            break;
        }
        case 3:{
            if((abs(xa-xb)==2&&abs(ya-yb)==1)||(abs(xa-xb)==1&&abs(ya-yb)==2)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            break;
        }
        default:{
            if(abs(xa-xb)==2&&abs(ya-yb)==2) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            break;
        }
    }
    return 0;
}