#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int aa[200005], bb[200005], cc[200005];
int n;
void work(int &aax, int &aal, int &aar, int l, int r)
{
    bb[l - 1] = cc[r + 1] = 1;
    for (int i = l; i <= r; ++i)
    {
        switch (aa[i])
        {
        case 1:
            bb[i] = bb[i - 1];
            break;
        case -1:
            bb[i] = -bb[i - 1];
            break;
        case 2:
        {
            if (bb[i - 1] >= 0)
                bb[i] = bb[i - 1] + 1;
            else
                bb[i] = bb[i - 1] - 1;
            break;
        }
        case -2:
        {
            if (bb[i - 1] >= 0)
                bb[i] = -bb[i - 1] - 1;
            else
                bb[i] = -bb[i - 1] + 1;
            break;
        }
        }
    }
    for (int i = r; i >= l; --i)
    {
        switch (aa[i])
        {
        case 1:
            cc[i] = cc[i + 1];
            break;
        case -1:
            cc[i] = -cc[i + 1];
            break;
        case 2:
        {
            if (cc[i + 1] >= 0)
                cc[i] = cc[i + 1] + 1;
            else
                cc[i] = cc[i + 1] - 1;
            break;
        }
        case -2:
        {
            if (cc[i + 1] >= 0)
                cc[i] = -cc[i + 1] - 1;
            else
                cc[i] = -cc[i + 1] + 1;
            break;
        }
        }
    }
    if (bb[r] > 0)
    {
        aax = bb[r] - 1;
        aal = l - 1;
        aar = n - r;
        return;
    }
    for (aal = l; aa[aal] > 0; ++aal)
        ;
    for (aar = r; aa[aar] > 0; --aar)
        ;
    if (bb[aal] < cc[aar])
    {
        aax = cc[aar] - bb[r];
        aal = l - 1;
        aar = n - aar + 1;
    }
    else
    {aax = bb[aal] - bb[r];aal = aal;aar = n - r;}
    return;
}
int main()
{
    int t;
    int n1, n2,mx, l, al, ar, ax;
    cin>>t;
    while(t--){cin>>n;mx = 0;n1 = n;n2 = 0;
        l = 0;for (int i = 1; i <= n; ++i) cin>>aa[i];
        aa[n + 1] = 0;
        for (int i = 0; i <= n + 1; ++i)
        {if (aa[i] == 0)
            {  if (l == 0)
                {    l = i + 1;
                }
                else
                {   if (aa[i - 1] == 0)   {l = i + 1;
                    }
            else
                    {  work(ax, al, ar, l, i - 1);  if (ax >= mx)
                        {n1 = al;
    n2 = ar;mx = ax;}l = i + 1;}}}}printf("%d %d\n", n1, n2);
}
}
