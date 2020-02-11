#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;
long long dp[101][101][101];
long long w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	long long& ret = dp[a][b][c];
	if (ret != 0)
		return ret;
	if (a < b && b < c)
		return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return ret;
}
int main()
{
	int a, b, c;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %lld\n", a,b,c,w(a, b, c));
	}
}