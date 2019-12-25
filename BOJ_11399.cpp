#include <stdio.h>
void bubble_sort(int *N,int len)
{
	int i, j;
	int temp;
	for (i = 0;i < len;i++)
	{
		for (j = 0;j <len-(i+1);j++)
		{
			if (N[j] > N[j + 1])
			{
				temp = N[j];
				N[j] = N[j + 1];
				N[j + 1] = temp;
			}
		}
	}
}

void ATM()
{
	int N;
	int arr[1001];
	int i;
	int sum = 0;
	int sum2 = 0;
	scanf("%d", &N);
	for (i = 0;i < N;i++)
		scanf("%d", &arr[i]);
	bubble_sort(arr,N);
	for (i = 0;i < N;i++)
	{
		sum += arr[i];
		sum2 += sum;
	}
	printf("%d", sum2);
}
int main()
{
	ATM();
}