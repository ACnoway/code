#include<iostream>
using namespace std;
int a[1003],f1[1003],f2[1003];
int main()
{
    int n=0,a1=0,a2=0;;
    int temp;
    while(cin>>temp){
        a[++n]=temp;
    }
    for(int i=1;i<=n;++i){
        f1[i]=1;
        for(int j=1;j<i;++j){
            if(a[i]>a[j]) f1[i]=max(f1[i],f1[j]+1);
        }
        a1=max(a1,f1[i]);
    }
    for(int i=1;i<=n;++i){
        f2[i]=1;
        for(int j=1;j<i;++j){
            if(a[i]<=a[j]) f2[i]=max(f2[i],f2[j]+1);
        }
        a2=max(a2,f2[i]);
    }
    cout<<a2<<endl<<a1<<endl;
    return 0;
}