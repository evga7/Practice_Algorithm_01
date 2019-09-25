#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
int main()
{
	long long  N, M;
	int i;
	int flag = 0;
	long long a, b;
	scanf("%lld %lld", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%lld %lld", &a, &b);
		if (a == b)
			continue;
		else
			flag = 1;
	}
	if (flag == 1)
	{
		printf("Wrong Answer");
		return 0;
	}
	else
	{
		flag = 0;
		for (i = 0; i < M; i++)
		{
			scanf("%lld %lld", &a, &b);
			if (a == b)
				continue;
			else
				flag = 1;
		}
	}
	if (flag == 1)
		printf("Why Wrong!!!");
	else
		printf("Accepted");
}