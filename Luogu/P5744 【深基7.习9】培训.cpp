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
struct node{
    string name;
    int age,score;
}a[10];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i].name>>a[i].age>>a[i].score;
    //                                                    600.0是为了转化成double，因为第二个是double类型的
    for(int i=0;i<n;++i) cout<<a[i].name<<' '<<a[i].age+1<<' '<<min(600.0,a[i].score*1.2)<<endl;
    return 0;
}