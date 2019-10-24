#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int N;
int op[4];
int arr[15];
int Max = -1000000001;
int Min = 1000000001;
void DFS(int plus, int sub, int mul, int div, int cnt,int sum)
{
	if (cnt == N)
	{
		Max = max(sum, Max);
		Min = min(sum, Min);
		return;
	}
	if (plus) DFS(plus - 1, sub, mul, div, cnt + 1, sum + arr[cnt]);
	if (sub) DFS(plus, sub-1, mul, div, cnt + 1, sum -arr[cnt]);
	if (mul) DFS(plus, sub, mul-1, div, cnt + 1, sum * arr[cnt]);
	if (div) DFS(plus, sub, mul, div-1, cnt + 1, sum / arr[cnt]);
}
int main()
{
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < 4; i++)
		scanf("%d", &op[i]);
	DFS(op[0],op[1],op[2],op[3],1,arr[0]);
	printf("%d\n%d", Max, Min);
}