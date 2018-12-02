#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9 + 5;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
const double PI = acos(-1);
using namespace std;
LL Scan_LL() ///输入外挂
{
	LL res = 0, ch, flag = 0;
	if ((ch = getchar()) == '-')
		flag = 1;
	else if (ch >= '0' && ch <= '9')
		res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + ch - '0';
	return flag ? -res : res;
}
int Scan_Int() ///输入外挂
{
	int res = 0, ch, flag = 0;
	if ((ch = getchar()) == '-')
		flag = 1;
	else if (ch >= '0' && ch <= '9')
		res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + ch - '0';
	return flag ? -res : res;
}
void Out(LL a) ///输出外挂
		{
	if (a > 9)
		Out(a / 10);
	putchar(a % 10 + '0');
}
int mu[MAXN], p[MAXN], k;
bool prime[MAXN];
void Mobius() {
	memset(prime, 0, sizeof(prime));
	mu[1] = 1;
	k = 0;
	for (int i = 2; i < MAXN; i++) {
		if (!prime[i]) {
			p[k++] = i;
			mu[i] = -1;
		}
		for (int j = 0; j < k && i * p[j] < MAXN; j++) {
			prime[i * p[j]] = 1;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
}

int main() {
	Mobius();
	int T;
	T = Scan_Int();
	for (int cas = 1; cas <= T; cas++) {
		LL a, b, c, d, k;
		a = Scan_LL();
		b = Scan_LL();
		c = Scan_LL();
		d = Scan_LL();
		k = Scan_LL();
		if (k == 0LL || k > b || k > d) {
			printf("Case %d: 0\n", cas);
			continue;
		}
		d /= k;
		b /= k;
		if (b > d)
			swap(b, d);
		LL ret = 0, ans = 0;
		for (LL i = 1; i <= b; i++)
			ret += mu[i] * (b / i) * (d / i);
		for (LL i = 1; i <= b; i++)
			ans += mu[i] * (b / i) * (b / i);
		ret -= (ans >> 1LL);
		printf("Case %d: %I64d\n", cas, ret);
	}
	return 0;
}
