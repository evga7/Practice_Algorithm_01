#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
queue<int>q;
int main()
{
	long long N;
	scanf("%lld", &N);
	long long i;
	long long num;
	int flag = 0;
	long long cnt = 0;
	while (1)
	{
		scanf("%lld", &num);
		if (num == -1)
			break;
		if (num == 0)
		{
			q.pop();
			cnt--;
		}
		else if (num > 0&&cnt<N)
		{
			q.push(num);
			cnt++;
		}
	}
	if (q.empty())
		printf("empty");
	else
	{
		while (!q.empty())
		{
			printf("%d ", q.front());
			q.pop();
		}
	}
}