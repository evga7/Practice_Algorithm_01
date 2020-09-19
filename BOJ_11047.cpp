#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
int N,K;
int arr[11];

int main()
{
	int res = 0;
	int i,j;
	scanf("%d %d", &N,&K);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (i = N-1; i >=0; i--)
	{
		while (arr[i] <= K)
		{
			K -= arr[i];
			res ++;
		}
	}
	printf("%d", res);
}


