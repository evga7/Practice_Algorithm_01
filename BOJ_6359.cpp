#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	int N;
	while (T--)
	{
		int dp[101] = { 0 };
		scanf("%d", &N);
		int i,j;
		for (i = 2; i <= N; i++)
		{
			for (j = i; j <=N; j+=i)
			{
				dp[j] = dp[j]==0 ? 1 : 0;
			}
		}
		int cnt = 0;
		for (i = 1; i <= N; i++)
			if (dp[i] == 0)
				cnt++;
		cout << cnt<<endl;
	}
}