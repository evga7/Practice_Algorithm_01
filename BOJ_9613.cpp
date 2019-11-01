#include <stdio.h>
int arr[101];
int gcd(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main(){
	int N, M;
	int i,j,k,l;
	long long sum;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		sum = 0;
		scanf("%d", &M);
		for (j = 1; j <= M; j++)
			scanf("%d", &arr[j]);

		for (k = 1; k <M; k++)
		{
			for (l = k + 1; l<= M;l++)
			{
				sum += gcd(arr[k], arr[l]);
			}
		}
		printf("%lld\n", sum);
	}
	
}