#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	int len, N;
	int i;
	int res1, res2;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &len, &N);
		res1 = 0, res2 = 0;
		for (i = 0; i < N; i++)
		{
			int num;
			scanf("%d", &num);
			int MAX = max(num, len - num);
			int MIN = min(num, len - num);
			res1 = max(MIN, res1);
			res2 = max(MAX, res2);
		}
		printf("%d %d\n", res1, res2);
	}
}