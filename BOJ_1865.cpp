#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 987654321
int N, M,T,W;
typedef pair<int, int>pi;
vector<pi>graph[501];
int d[501];
bool iscycle = false;
void solve()
{
	int i, j, k;
	d[1] = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			for (auto next : graph[j])
			{
				int next_x = next.first;
				int cost = next.second;
				if (d[next_x] > d[j] + cost)
				{
					d[next_x] = d[j] + cost;
					if (i == N) iscycle = true;
				}
			}
		}
	}
}
int main(void)
{
	int i, j;
	cin >> T;
	while (T--)
	{
		cin >> N >> M>>W;
		int A, B, C;
        iscycle=false;
		for (i = 1; i <= N; i++)
			graph[i].clear();
		for (i = 0; i < M; i++)
		{
			cin >> A >> B >> C;
			graph[A].push_back({ B,C });
			graph[B].push_back({ A,C });
		}
		for (i = 0; i < W; i++)
		{
			cin >> A >> B >> C;
			graph[A].push_back({ B, -C });
		}
		for (i = 1; i <= N; i++)
			d[i] = MAX;
		solve();
		if (iscycle)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
