#include <stdio.h>
void sadist()
{
	int N;
	int i;
	int num;
	int cnt = 0;
	scanf("%d", &N);
	for (i = 1; i <=N; i++)
	{
		scanf("%d", &num);
		if (i != num)
			cnt++;
	}
	printf("%d", cnt);
}
int main()
{
	sadist();
}