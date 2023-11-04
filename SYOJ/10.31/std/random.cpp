#include <bits/stdc++.h>

#define For(i, l, r) for(register int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for(register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define debug(x) cout << #x << ": " << x << endl
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

inline bool chkmin(int &a, int b) {return b < a ? a = b, 1 : 0;}
inline bool chkmax(int &a, int b) {return b > a ? a = b, 1 : 0;}

inline int read() {
    int x = 0, fh = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return x * fh;
}

void File() {
	freopen ("random.in", "r", stdin);
	freopen ("random.out", "w", stdout);
}

const double Gamma = 0.57721566490153286060651209;

int main () {

	File();

	long long n; cin >> n;

	if (n <= 300) {
		double ans = .0;
		For (i, 1, n)
			ans += 1.0 / i;
		return printf ("%.6lf\n", ans), 0;
	}
	printf ("%.6lf\n", log(n) + 1.0 / (2 * n) + Gamma);

	return 0;
}
