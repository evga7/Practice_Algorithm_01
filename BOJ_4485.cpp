#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 987654321
int N;
typedef pair<int, int>pi;
int arr[130][130];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int dist[130][130];
int solve()
{
	priority_queue<pair<int,pi>, vector<pair<int, pi>>, greater<pair<int,pi>>>pq;
	pq.push({ 0,{0,0} });
	while (!pq.empty())
	{
		int cur_x = pq.top().second.first;
		int cur_y = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		int i;
		if (cur_x == N - 1 && cur_y == N - 1)
			return dist[N - 1][N - 1]+arr[N-1][N-1];
		for (i = 0; i < 4; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)
				continue;
			int n_cost = arr[cur_x][cur_y] + cost;
			if (dist[n_x][n_y] > n_cost)
			{
				dist[n_x][n_y] = n_cost;
				pq.push({ n_cost,{n_x,n_y} });
			}
		}
	}
}
int main() {
	int cnt = 1;
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
		int i, j;
		int num;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				cin >> num;
				arr[i][j] = num;
				dist[i][j] = MAX;
			}
		}
		cout<<"Problem "<<cnt++<<": "<<solve()<<"\n";
		
	}

}