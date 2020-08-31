#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int T,N, M,W;
vector<int>score;
vector<int>v[1001];
int indegrees[1001];
int res[1001];
void bfs()
{
	int i;
	queue<int>q;
	for (i = 0; i < N; i++)
	{
		if (indegrees[i] == 0)
		{
			q.push(i);
			//res[i] = score[i];
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			res[next] = max(res[next], res[cur] + score[cur]);
			if (--indegrees[next] == 0)
				q.push(next);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	int i;
	while (T--)
	{
		cin >> N >> M;
		int num;
		for (i = 0; i < N; i++)
		{
			cin >> num;
			score.push_back(num);
		}
		int a, b;
		for (i = 0; i < M; i++)
		{
			cin >> a >> b;
			v[a-1].push_back(b-1);
			indegrees[--b]++;
		}
		cin >> W;
		W--;
		bfs();
		cout << res[W]+score[W]<<"\n";
		score.clear();
		fill(indegrees, indegrees + N + 1, 0);
		fill(res, res + N + 1, 0);
		for (i = 0; i <= N; i++)
			v[i].clear();
	}
	

}
