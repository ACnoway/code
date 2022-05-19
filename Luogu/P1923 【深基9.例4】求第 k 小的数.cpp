#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int a[5000006];
int k,cnt;
void work(int l,int r){
    int i=l,j=r;
    int mid=a[(l+r)>>1];
    do{
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(k<=j) work(l,j);
    else if(i<=k) work(i,r);
    else{
        write(a[j+1]);
        return;
    }
}
int main()
{
    int n;
    n=read();
    k=read();
    for(int i=0;i<n;++i) a[i]=read();
    work(0,n-1);
    return 0;
}