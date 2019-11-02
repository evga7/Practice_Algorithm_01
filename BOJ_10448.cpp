#include <stdio.h>


int sum[1001];
int N;
int eureka(int num)
{
	int i, j, k;
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= num; j++)
		{
			for (k = 1; k <= num; k++)
			{
				int result = sum[i] + sum[j] + sum[k];
				if (result == num)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int i;
	int num;
	scanf("%d", &N);
	for (i = 1; i < 1001; i++)
	{
		sum[i] = (i*(i + 1)) / 2;
	}
	while (N--)
	{
		scanf("%d", &num);
		printf("%d\n", eureka(num));
	}
}