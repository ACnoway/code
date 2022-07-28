#include <iostream>
#include <cstdio>
using namespace std;
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int a[4][4];
int t[30];
bool flag[30][30];
int a1,a2;
int main()
{
    char c;
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            c=getchar();
            while(c<'A'||c>'Z') c=getchar();
            a[i][j]=c;
        }
    }
    for(int i=1;i<=3;++i){
        int x=a[i][1],y=a[i][2],z=a[i][3];
        if(x==y&&!flag[x][z]){
            if(x==z) a1++;
            else a2++;
            flag[x][z]=true;
            flag[z][x]=true;
        }
        else if(x==z&&!flag[x][y]){
            if(x==y) a1++;
            else a2++;
            flag[x][y]=true;
            flag[y][x]=true;
        }
        else if(y==z&&!flag[x][z]){
            if(x==z) a1++;
            else a2++;
            flag[x][z]=true;
            flag[z][x]=true;
        }
    }
    for(int i=1;i<=3;++i){
        int x=a[1][i],y=a[2][i],z=a[3][i];
        if(x==y&&!flag[x][z]){
            if(x==z) a1++;
            else a2++;
            flag[x][z]=true;
            flag[z][x]=true;
        }
        else if(x==z&&!flag[x][y]){
            if(x==y) a1++;
            else a2++;
            flag[x][y]=true;
            flag[y][x]=true;
        }
        else if(y==z&&!flag[x][z]){
            if(x==z) a1++;
            else a2++;
            flag[x][z]=true;
            flag[z][x]=true;
        }
    }
    int x=a[1][1],y=a[2][2],z=a[3][3];
    if(x==y&&!flag[x][z]){
        if(x==z) a1++;
        else a2++;
        flag[x][z]=true;
        flag[z][x]=true;
    }
    else if(x==z&&!flag[x][y]){
        if(x==y) a1++;
        else a2++;
        flag[x][y]=true;
        flag[y][x]=true;
    }
    else if(y==z&&!flag[x][z]){
        if(x==z) a1++;
        else a2++;
        flag[x][z]=true;
        flag[z][x]=true;
    }
    int x=a[1][3],y=a[2][2],z=a[3][1];
    if(x==y&&!flag[x][z]){
        if(x==z) a1++;
        else a2++;
        flag[x][z]=true;
        flag[z][x]=true;
    }
    else if(x==z&&!flag[x][y]){
        if(x==y) a1++;
        else a2++;
        flag[x][y]=true;
        flag[y][x]=true;
    }
    else if(y==z&&!flag[x][z]){
        if(x==z) a1++;
        else a2++;
        flag[x][z]=true;
        flag[z][x]=true;
    }
    write(a1);
    putchar('\n');
    write(a2);
    return 0;
}