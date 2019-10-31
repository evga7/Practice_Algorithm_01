#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int arr[100001];
int N, M;
int binary_search(int num)
{
	int left = 0;
	int right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == num)
			return 1;
		else if (arr[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}
int main()
{
	int i;
	int num;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d",&M);
	sort(arr, arr + N);
	for (i = 0; i < M; i++)
	{
		scanf("%d",&num);
		printf("%d\n", binary_search(num));
	}
}