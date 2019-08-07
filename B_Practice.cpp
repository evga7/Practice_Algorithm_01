#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int prime[1001];
int arr[101];
int main() {
	int N;
	int i, j;
	int cnt = 0;
	memset(prime, 1, sizeof(prime));
	prime[1] = 0;
	for (i = 2; i < 11; i++)
	{
		for (j = i * i; j <= i; j++)
		{
			if (prime[i])
			{
				prime[j] = 0;
			}
		}
	}
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (prime[arr[i]])
			cnt++;
	}
	printf("%d", cnt);
}