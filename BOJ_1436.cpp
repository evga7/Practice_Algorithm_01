#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int num = 666;
	int i = 1;
	int N;
	string str;
	scanf("%d", &N);
	int j;
	while (i<N)
	{
		num++;
		int flag = 0;
		int cnt = 0;
		int temp=num;
		while (temp > 0)
		{
			int s = temp % 10;
			if (s == 6)
				cnt++;
			else
				cnt = 0;
			if (cnt == 3)
			{
				flag = 1;
				break;
			}
			temp /= 10;
		}
		if (flag)
		{
			i++;
			if (i == N)
			{
				break;
			}
		}
	}
	printf("%d", num);
}