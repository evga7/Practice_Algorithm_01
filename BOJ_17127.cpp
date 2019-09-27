#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int arr[11];
int res = 0;
int main() {
	int N;
	scanf("%d", &N);
	int i, j;
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int M = N - 3;
	int sum;
	int mul = 1;
	for (i = 0; i < N; i++)
	{
		sum = 0;
		mul = 1;
		if (i + M <=N)
		{
			for (j = 0; j < N; j++)
			{
				if (j >= i && j < i + M)
					mul *= arr[j];
				else
					sum += arr[j];
			}
			sum += mul;
			res = max(sum, res);
		}
	}
	printf("%d", res);
}