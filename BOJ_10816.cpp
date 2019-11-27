#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int arr[500001];
int N, M;
int lower_binary(int num)
{
	int left = 0;
	int right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] >= num)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right;
}
int upper_binary(int num)
{
	int left = 0;
	int right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > num)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right;
}
int main()
{
	int i, j;
	int num;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &M);
	sort(arr, arr + N);
	for (i = 0; i < M; i++)
	{
		scanf("%d", &num);
		int cnt = 0;
		cnt = upper_binary(num)-lower_binary(num);
		printf("%d ", cnt);
	}

}