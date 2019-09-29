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
	int size1, size2;
	size1 = str1.size();
	size2 = str2.size();
	for (i = 1; i <=size1; i++)
		dp[i][0] = i;

	for (i = 1; i <=size2; i++)
		dp[0][i] = i;

	for (i = 1; i <=size1; i++)
	{
		for (j = 1; j <=size2; j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
				dp[i][j] =1+min({ dp[i - 1][j], dp[i][j - 1],dp[i - 1][j - 1]});
		}
	}
	printf("%d", dp[size1][size2]);
}
