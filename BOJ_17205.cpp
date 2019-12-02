#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
long long res = 0;
long long dp[11];
int N;
string str;
int main()
{
	int i;
	scanf("%d", &N);
	cin >> str;
	int len = str.length();
	dp[1] = 26;
	for (i = 2; i < 11; i++)
		dp[i] = dp[i - 1] * 26 + 26;
	for (i = 0; i < len; i++)
	{
		res += (str[i] - 'a')*dp[N - i - 1] + (str[i]-'a' + 1);
	}
	printf("%lld", res);

}