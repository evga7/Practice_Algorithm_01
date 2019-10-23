#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int back[1001];
stack<int>s;
void DFS(int index)
{
	s.push(arr[index]);
	if (back[index] != -1)
	{
		DFS(back[index]);
	}
	return;
}
int main()
{
	int i, j;
	int min = 0;
	int N;
	int Max = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < N; i++)
	{
		back[i] = -1;
		min = 0;
		for (j = 0; j <i; j++)
		{
			if (min <dp[j]&&arr[i]>arr[j])
			{
				min = dp[j];
				back[i] = j;
			}
		}
		dp[i] = min + 1;
		Max = max(Max, dp[i]);
	}
	for (i = 0; i < N; i++)
	{
		if (dp[i] == Max)
		{
			DFS(i);
            break;
		}
	}
    printf("%d\n",Max);
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
}