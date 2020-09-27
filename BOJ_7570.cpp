#include <string> 
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 987654321
using namespace std;
int N,M;
int dp[1000001];
int res;
int main()
{
	cin >> N;
	int i,j;
	int num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		dp[num] = dp[num - 1] + 1;
		res = max(res, dp[num]);

	}
	cout << N-res;

}