#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int arr[100001];
int main()
{
	int N;
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d",&arr[i]);
	sort(arr, arr + N);
	int ans = 0;
	for (i = N - 1; i >= 0; i--)
	{
		ans = max(ans, arr[i] * (N - i));
	}
	printf("%d", ans);
}