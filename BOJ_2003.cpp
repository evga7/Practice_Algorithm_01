#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int arr[10001];
int res = 0;
int main()
{
	int N,M;
	cin >> N>>M;
	int i,j;
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < N; i++)
	{
		int sum = arr[i];
		if (sum == M)
		{
			res++;
			continue;
		}
		for (j = i+1; j < N; j++)
		{
			sum += arr[j];
			if (sum >= M)
			{
				if (sum == M)
				{
					res++;
				}
				break;
			}
		}
	}
	cout << res;
}


