#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 1e15
typedef long long int ll;
int N, M;
int arr[302][302];
ll dist[302][302];
typedef pair<ll, pair<int, int>> pi;
vector<pi>v[302][302];
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int main() {

	int i, j,k;
	cin >> N >> M;
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <=M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -2)
				arr[i][j] = 0;
		}
	}
	arr[0][0] = arr[0][1] = arr[1][0] = -1;
	arr[N][M + 1] = arr[N + 1][M] = arr[N+1][M+1] = -1;
	for (i = 0; i <= N+1; i++)
	{
		for (j = 0; j <= M+1; j++)
		{
			if (arr[i][j] == -1)continue;
				for (k = 0; k < 8; k++)
				{
					int n_x, n_y;
					n_x = i + dx[k];
					n_y = j + dy[k];
					if (arr[n_x][n_y]==-1 || n_x < 0 || n_x > N+1 || n_y < 0 || n_y > M+1) continue;
					v[i][j].push_back({ arr[n_x][n_y],{n_x,n_y} });
				}
		}
	}
	for (i = 0; i <=N+1; i++)
		for (j = 0; j <=M+1; j++)
			dist[i][j] = MAX;
	priority_queue<pi,vector<pi>,greater<pi>>pq;
	pq.push({ 0,{N+1,0} });
	dist[N+1][0] = 0;
	while (!pq.empty())
	{
		auto tmp = pq.top();
		pq.pop();
		ll cost = tmp.first;
		i = tmp.second.first;
		j = tmp.second.second;
		if (cost > dist[i][j])continue;
		for (auto next : v[i][j])
		{
			ll n_cost = next.first+dist[i][j];
			int n_x = next.second.first;
			int n_y = next.second.second;
			if (dist[n_x][n_y] >n_cost)
			{
				dist[n_x][n_y] = n_cost;
				pq.push({ n_cost,{n_x,n_y} });
			}
		}
	}
	if (dist[0][M + 1] == MAX)cout << -1;
	else cout << dist[0][M + 1];
}