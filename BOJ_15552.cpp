#include <stdio.h>
void fast_sum()
{
	int N;
	int i;
	int A, B;
	scanf("%d", &N);
	for (i = 0;i < N;i++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}
}
int main()
{
	fast_sum();
}
