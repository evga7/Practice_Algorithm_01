#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int arr[9];
int chk[9];
vector<int> v;
int result = 0;

int Max(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int n, int cnt)
{
	if (cnt == n)
	{
		int i;
		int sum = 0;
		for (i = 1; i < n; i++)
			sum += abs(v[i] - v[i - 1]);
		result = Max(sum, result);
	}
	int i;
	for (i = 0; i < n; i++)
	{
		if (chk[i])
			continue;
		v.push_back(arr[i]);
		chk[i] = 1;
		dfs(n, cnt + 1);
		v.pop_back();
		chk[i] = 0;
	}
}
int main() {
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dfs(n, 0);
	printf("%d", result);
}