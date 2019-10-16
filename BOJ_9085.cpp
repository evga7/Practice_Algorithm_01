#include <stdio.h>
void N_sum()
{
	int N,M;
	int i,j;
	int sum;
	int num;
	scanf("%d", &N);
	for (i = 0;i < N;i++)
	{
		sum = 0;
		scanf("%d", &M);
		for (j = 0;j < M;j++)
		{
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
	}
}
int main()
{
	N_sum();
}