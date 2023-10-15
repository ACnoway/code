#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
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
int a[1000006],b[1000006];
int t[6000006];
int main()
{
    freopen("task.in","r",stdin);
    freopen("task.out","w",stdout);
   int n, i, k;
   int sumA = 0;
   int result = 1000000000;
 
   n=read();
 
 
   for( i = 0; i < n; i++)
   {
       a[i]=read(),b[i]=read();
       sumA = sumA+a[i];
   }
 
   for( i = 0; i < n; i++)
    t[i] = 0;
 
   for( k = 0; k < n; k++)
   {
       for( i = sumA; i >= 0; i--)
       {
           if(i >= a[k] )
            t[i] = t[i]+b[k] < t[i-a[k]]?t[i]+b[k]:t[i-a[k]];
           else
            t[i] = t[i]+b[k];
       }
   }
   for( i = 0; i<= sumA; i++)
   {
       k = i>t[i]?i:t[i];
       if(result>k)
        result = k;
   }
   printf("%d\n", result);
   return 0;
}