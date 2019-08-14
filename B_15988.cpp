#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long arr[1000001];
int main()
{
	int N;
	int i;
	int num;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	scanf("%d", &N);
	for (i = 4; i <=1000000; i++)
	{
		arr[i] = (arr[i - 1]+ arr[i - 2]+ arr[i - 3])%1000000009;
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		printf("%lld\n", arr[num]%1000000009);
	}

}