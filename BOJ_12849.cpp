#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;
long long DP[8];
int N;
int temp[8];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int i;
	DP[0] = 1;
	while (N--)
	{
		int temp[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		temp[0] = (DP[1] + DP[2]) % 1000000007;
		temp[1] = (DP[0] + DP[2] + DP[3]) % 1000000007;
		temp[2] = (DP[0] + DP[1] + DP[3] + DP[5]) % 1000000007;
		temp[3] = (DP[1] + DP[2] + DP[4] + DP[5]) % 1000000007;
		temp[4] = (DP[3] + DP[5] + DP[6]) % 1000000007;
		temp[5] = (DP[2] + DP[3] + DP[4] + DP[7]) % 1000000007;
		temp[6] = (DP[4] + DP[7]) % 1000000007;
		temp[7] = (DP[5] + DP[6]) % 1000000007;
		DP[0] = temp[0];
		DP[1] = temp[1];
		DP[2] = temp[2];
		DP[3] = temp[3];
		DP[4] = temp[4];
		DP[5] = temp[5];
		DP[6] = temp[6];
		DP[7] = temp[7];
	}
	cout << DP[0] % 1000000007;

}

