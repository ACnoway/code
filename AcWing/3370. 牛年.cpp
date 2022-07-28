#include <iostream>
#include <cstdio>
#include <cmath>
#include <unordered_map>
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
string t[13]={"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
int n;
string who,how,what,temp,from;
unordered_map<string,int> m;
int main()
{
    cin>>n;
    m["Bessie"]=0;
    while(n--){
        cin>>who>>temp>>temp>>how>>what>>temp>>temp>>from;
        int wfm=m[from],k=1;
        while(wfm<0) wfm+=12;
        while(wfm>=12) wfm-=12;
        string love=t[wfm];
        if(how=="previous"){
            if(wfm==0) wfm=12;
            wfm--;
            while(t[wfm]!=what){
                if(wfm==0) wfm=12;
                wfm--;
                k++;
            }
            m[who]=m[from]-k;
        }
        else{
            wfm++;
            while(t[wfm%12]!=what){
                wfm++;
                k++;
            }
            m[who]=m[from]+k;
        }
        //cout<<m[who]<<endl;
        if(who=="Elsie") break;
    }
    write(abs(m["Elsie"]-m["Bessie"]));
    return 0;
}