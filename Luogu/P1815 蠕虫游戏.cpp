#include <iostream>
using namespace std;
struct node{
    int x,y;
}s[25];
int n,error;
int a[5][2]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
void go(int d){
    int x=s[1].x,y=s[1].y;
    s[1].x+=a[d][0];
    s[1].y+=a[d][1];
    if(s[1].x>50 || s[1].y>50|| s[1].x<1|| s[1].y<1){error=2;return;}
    for(int i=2;i<=20;++i){
        swap(s[i].x,x);
        swap(s[i].y,y);
        //if(s[i].x>50 || s[i].y>50|| s[i].x<1|| s[i].y<1){error=2;return;}
        if(s[i].x==s[1].x && s[i].y==s[1].y){error=1;return;}
    }

}
int main()
{
    while (1){
        error=0;
        for(int i=1;i<=20;i++) s[i].x=25,s[i].y=31-i;
        cin>>n;
        if(n==0) break;
        string op;
        cin>>op;
        for(int i=0;i<n;++i){
            switch(op[i]){
                case 'E':
                    go(0);
                    break;
                case 'W':
                    go(1);
                    break;
                case 'S':
                    go(2);
                    break;
                case 'N':
                    go(3);
                    break;
            }
            if(error==1){
                cout<<"The worm ran into itself on move "<<i+1<<'.'<<endl;
                break;
            }
            else if(error==2){
                cout<<"The worm ran off the board on move "<<i+1<<'.'<<endl;
                break;
            }
        }
        if(error==0){
            cout<<"The worm successfully made all "<<n<<" moves."<<endl;
        }
        
    }
    return 0;
}