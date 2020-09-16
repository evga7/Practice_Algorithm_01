#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 987654321
int N, M;
typedef pair<int, int>pi;
vector<pi>graph[501];
long long int d[501];
bool iscycle = false;
void solve()
{
	int i, j,k;
	d[1] = 0;
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <=N; j++)
		{
			for (auto next : graph[j])
			{
				int next_x = next.first;
				long long int cost = next.second;
				if (d[j] != MAX && d[next_x] > d[j] + cost)
				{
					d[next_x] = d[j] + cost;
					if (i == N - 1&&N>2) iscycle = true;
				}
			}
		}
	}
}
int main(void)
{
	int i, j;
	cin >> N >> M;
	int A, B,C;
	for (i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
	}
	for (i = 1; i <=N; i++)
		d[i] = MAX;
	solve();
	if (iscycle)
		cout << "-1";
	else
		for (i = 2; i <= N; i++)
			d[i] == MAX ? cout << "-1" << "\n" : cout << d[i]<<"\n";
}
