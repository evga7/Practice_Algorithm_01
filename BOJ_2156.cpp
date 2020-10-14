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
int N;
int dp[10001];
int arr[10001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int i, j;
	cin >> N;
	
	for (i = 1; i <=N; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (i =2; i <= N; i++)
		dp[i] = max({ arr[i] + arr[i - 1] + dp[i - 3], dp[i - 2] + arr[i],dp[i - 1] });
	cout << dp[N];
}
