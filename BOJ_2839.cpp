#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
int res = 0;
int N;
int main()
{
	scanf("%d", &N);
	while (1)
	{
		if (N % 5 == 0)
		{
			res += N / 5;
			break;
		}
		if (N<=0)
		{
			res = -1;
			break;
		}
		N -= 3;
		res++;
	}
	printf("%d", res);
}
