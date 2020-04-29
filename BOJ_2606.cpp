#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
using namespace std;
int N, M;
int arr[101][101];
int visited[101];
int res = 0;
void DFS(int a)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		if (arr[a][i]&&!visited[i])
		{
			res++;
			visited[i] = 1;
			DFS(i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int i;
	int a, b;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[b][a] = 1;
		arr[a][b] = 1;
	}
	visited[1] = 1;
	DFS(1);
	cout << res;
}

