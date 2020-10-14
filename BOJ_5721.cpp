#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <stack>
#include <set>
#include <map>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int i, j;
	while (1)
	{
		cin >> N >> M;
		int arr[100001] = { 0, };
		int res[100001] = { 0, };
		int dp[100001] = { 0, };
		int dp2[100001] = { 0, };
		if (N == 0 && M == 0)
			break;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				cin >> arr[j];
			}
			dp[1] = arr[1];
			for (j = 2; j <= M; j++)
			{
				dp[j] = max(dp[j - 2] + arr[j], dp[j - 1]);
			}
			dp2[i] = dp[M];
		}
		res[1] = dp2[1];
		for (i = 2; i <= N; i++)
		{
			res[i] = max(dp2[i] + res[i - 2], res[i - 1]);
		}
		cout << res[N] << "\n";
	}


}