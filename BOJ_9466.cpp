#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
using namespace std;
int T;
int visited[100001];
int chk[100001];
int arr[100001];
int res = 0;
int N;
void solve(int start)
{
	int i;
	visited[start] = 1;
	int next = arr[start];
	if (!visited[next])
		solve(next);
	else if (!chk[next])
	{
		res++;
		for (i = next; i != start; i = arr[i])
			res++;
	}
	chk[start] = 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	int i;
	int num;
	while (T--)
	{
		cin >> N;
		res = 0;
		memset(chk, 0, sizeof(chk));
		memset(visited, 0, sizeof(visited));
		for (i = 1; i <= N; i++)
		{
			cin >> arr[i];
		}
		for (i = 1; i <= N; i++)
		{
			if (!chk[i])
				solve(i);
		}
		cout << (N - res) << "\n";
	}
}

