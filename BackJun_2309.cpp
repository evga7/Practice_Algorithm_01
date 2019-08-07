#include <stdio.h>
int arr[10];
int arr2[101];
int main() {
	int i,j,k;
	int sum = 0;
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		arr2[arr[i]] = 1;
		sum += arr[i];
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i != j&&sum-arr[i]-arr[j]==100)
			{
				arr2[arr[i]] = 0;
				arr2[arr[j]] = 0;
				for (i = 1; i < 100; i++)
				{
					if (arr2[i])
						printf("%d\n", i);
				}
				return 0;
			}
		}
	}
	
}