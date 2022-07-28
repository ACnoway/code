#include <cstdio>
#define MAXN 1000005
using namespace std;
template <class T>
inline T over_templatefunction_read(void)
{
   T ans;
   static bool f;
   static char us = getchar();
   ans = 0;
   f = false;
   while (us < 48 || us > 57)
   {
      f |= (us == 45);
      us = getchar();
   }
   while (us > 47 && us < 58)
   {
      ans = (ans << 1) + (ans << 3) + (us ^ 48);
      us = getchar();
   }
   return f ? -ans : ans;
}
template <typename T>
void over_voidfunction_put(T x)
{
   if (x < 0)
   {
      return putchar(45), over_voidfunction_put(-x);
   }
   else
   {
      putchar(x > 9 ? over_voidfunction_put(x / 10), x % 10 | 48 : x % 10 | 48);
   }
}
long long usarray[MAXN];

int main()
{
   int n, m, q;
   n = over_templatefunction_read<int>();
   m = over_templatefunction_read<int>();
   q = over_templatefunction_read<int>();
   for (int i = 1; i <= n; ++i)
   {
      usarray[i] = over_templatefunction_read<int>();
      usarray[i] %= 998244353;
   }
   for (int i = n; i >= 2; --i)
   {
      usarray[i] -= usarray[i - 1];
      usarray[i] %= 998244353;
   }
   for (int i = n; i >= 2; --i)
   {
      usarray[i] -= usarray[i - 1];
      usarray[i] %= 998244353;
   }
   int l, r, x;
   for (int i = 1; i <= m; ++i)
   {
      l = over_templatefunction_read<int>();
      r = over_templatefunction_read<int>();
      x = over_templatefunction_read<int>();
      usarray[l] += x;
      usarray[r + 1] -= (r - l + 2) * x;
      usarray[r + 2] += (r - l + 1) * x;
      usarray[i] %= 998244353;
   }
   for (int i = 2; i <= n; ++i)
   {
      usarray[i] += usarray[i - 1];
      usarray[i] %= 998244353;
   }
   for (int i = 2; i <= n; ++i)
   {
      usarray[i] += usarray[i - 1];
      usarray[i] %= 998244353;
   }
   for (int i = n - 1; i >= 1; --i)
   {
      usarray[i] += usarray[i + 1];
      usarray[i] %= 998244353;
   }
   for (int i = n - 1; i >= 1; --i)
   {
      usarray[i] += usarray[i + 1];
      usarray[i] %= 998244353;
   }
   for (int i = 1; i <= q; ++i)
   {
      l = over_templatefunction_read<int>();
      r = over_templatefunction_read<int>();
      x = over_templatefunction_read<int>();
      printf("%lld ", (998244353 + (x * usarray[l] - x * (r - l + 2) * usarray[r + 1] + x * (r - l + 1) * usarray[r + 2] - (x - 1) * (usarray[l] - usarray[l + 1] - usarray[r + 1] + usarray[r + 2])) % 998244353) % 998244353);
   }
   return 0;
}