#include <iostream>
#include <queue>
#include <algorithm>
int N;
int arr[1000001];
int B, C;
long long cnt = 0;
int main()
{
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);
	for (i = 0; i < N; i++)
	{
		int num = arr[i];
		num -= B;
		cnt++;
		if (num > 0)
		{
			if (num%C == 0)
				cnt += num / C;
			else
				cnt += (num / C) + 1;
		}
	}
	printf("%lld", cnt);
}
