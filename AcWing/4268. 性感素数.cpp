#include<iostream>
using namespace std;
bool check(int x){
    if(x==1) return 0;
    if(x==2) return 1;
    if(x%2==0) return 0;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    if((check(n)&&check(n-6))||(check(n)&&check(n+6))){
        if(check(n-6)) cout<<"Yes"<<endl<<n-6<<endl;
        else if(check(n+6)) cout<<"Yes"<<endl<<n+6<<endl;
    }
    else {
        cout<<"No"<<endl;
        n++;
        while(!((check(n)&&check(n-6))||(check(n)&&check(n+6)))) n++;
        cout<<n<<endl;
    }
    return 0;
}