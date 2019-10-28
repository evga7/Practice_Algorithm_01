#include <stdio.h>
void plug(int N)
{
	int i;
	int num;
	int cnt;
	scanf("%d", &num);
	cnt = num;
	for (i = 1; i < N; i++)
	{
		scanf("%d", &num);
		cnt += num-1;
	}
	printf("%d", cnt);
}
int main()
{
	int N;
	scanf("%d", &N);
	plug(N);
}