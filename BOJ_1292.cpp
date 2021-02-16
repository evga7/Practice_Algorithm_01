#include <bits/stdc++.h>
#include <unordered_map>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int N, M;
int num;
int res = 0;
int arr[1001];
int sum[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int i, j;
	int idx = 1;
	for (i = 1; i <= M; i++)
	{
		for (j =0; j <i&&idx<=1000; j++)
		{
			arr[idx++] = i;
		}
	}
	for (i = N;i<= M; i++)
	{
		res += arr[i];
	}
	cout << res;
}