#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[1001][10001];
int main()
{
	int i, j;
	string str1, str2;
	cin >> str1 >> str2;
	for (i = 1; i <=str1.size(); i++)
	{
		for (j = 1; j <=str2.size(); j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d", dp[i-1][j-1]);
}
