#include <stdio.h>

void print_N()
{
	int N;
	int i;
	scanf("%d", &N);
	for (i = 1;i <=N;i++)
		printf("%d\n", i);
}
int main()
{
	print_N();
}