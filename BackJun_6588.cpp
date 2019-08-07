#include <stdio.h>
#include <string.h>
#define MAX 1000001
int isprime[MAX];
void goldbach(int N)
{
	int i,j;
	int index_i, index_j;
	int max = 0;
	index_i = index_j = 0;
	for (i = 3; i <= N/2; i += 2)
	{
		if (isprime[i])
		{
			index_i = i;
			index_j = N - i;
			if (isprime[index_j])
			{
				printf("%d = %d + %d\n", N, index_i, index_j);
				return;
			}
		}
		
	}
	printf("Goldbach's conjecture is wrong.");
}
void prime_number()
{
	int i, j;
	for (i = 2; i*i <MAX; i++)
	{
		if (isprime[i])
		{
			for (j = i * i; j < MAX; j += i)
			{
				isprime[j] = 0;
			}
		}
	}
}
int main() {
	int N;
	memset(isprime, 1, sizeof(isprime));
	prime_number();
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		goldbach(N);
	}
}