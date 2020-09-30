#include <iostream>
#include <cstring> 
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 987654321
using namespace std;
typedef pair<int, int> pi;
typedef long long int ll;
int arr[51][51];
int dist[51][51];
int N;
int res = MAX;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
void solve()
{
	priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>>pq;
	pq.push({ 0,{0,0} });
	dist[0][0] = 0;
	int i;
	while (!pq.empty())
	{
		auto tmp = pq.top();
		pq.pop();
		int cost = tmp.first;
		int cur_x = tmp.second.first;
		int cur_y = tmp.second.second;
		for (i = 0; i < 4; i++)
		{
			int n_x = dx[i] + cur_x;
			int n_y = dy[i] + cur_y;
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)continue;
			int c = dist[cur_x][cur_y] + arr[n_x][n_y];
			if (dist[n_x][n_y] > c)
			{
				dist[n_x][n_y] = c;
				pq.push({ c,{n_x,n_y} });
			}
		}

	}

}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1)
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
			dist[i][j] = MAX;
		}
	}
	solve();
	printf("%d", dist[N - 1][N - 1]);
}