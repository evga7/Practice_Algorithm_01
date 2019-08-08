#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
vector<int> v;
int arr[12];
int op[4];
int n;
int MIN = 2100000000;
int MAX = -2100000000;
int Max(int a, int b)
{
	return a > b ? a : b;
}
int Min(int a, int b)
{
	return a < b ? a : b;
}
void dfs(int node,int plus,int sub,int mul,int div,int sum)
{
	if (node == n)
	{
		MAX = Max(MAX, sum);
		MIN = Min(MIN, sum);
	}
	if (plus < op[0])
		dfs(node + 1, plus + 1, sub, mul, div, sum + arr[node]);
	if (sub <op[1])
		dfs(node + 1, plus, sub+1, mul, div, sum-arr[node]);
	if (mul < op[2])
		dfs(node + 1, plus, sub , mul+1, div, sum * arr[node]);
	if (div < op[3])
		dfs(node + 1, plus, sub, mul, div+1, sum / arr[node]);

}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &op[i]);
	}
	dfs(1, 0, 0, 0, 0, arr[0]);
	printf("%d\n%d", MAX, MIN);

}