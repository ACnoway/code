#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int p1,p2,p3;
char a[103];
int main()
{
    cin>>p1>>p2>>p3;
    cin>>a+1;
    for(int i=1;i<=strlen(a+1);++i){
        if(i>1&&a[i]=='-'&&((islower(a[i+1])&&islower(a[i-1])&&a[i+1]>a[i-1])||(isdigit(a[i+1])&&isdigit(a[i-1])&&a[i+1]>a[i-1]))){
            if(p1==3){//输出*，顺序不重要
                for(int j=a[i-1]+1;j<a[i+1];++j){
                    for(int k=1;k<=p2;++k) putchar('*');
                }
            }
            else{
                if(p3==1){
                    for(int j=a[i-1]+1;j<a[i+1];++j){
                        for(int k=1;k<=p2;++k){
                            if(islower(j)) putchar(j-(p1-1)*32);
                            else putchar(j);
                        }
                    }
                }
                else{
                    for(int j=a[i+1]-1;j>a[i-1];--j){
                        for(int k=1;k<=p2;++k){
                            if(islower(j)) putchar(j-(p1-1)*32);
                            else putchar(j);
                        }
                    }
                }
            }
        }
        else putchar(a[i]);
    }
    return 0;
}