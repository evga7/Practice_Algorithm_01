#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
vector<int>v;
int main()
{
	long long N;
	int flag;
	int flag2 = -1,flag3 = -1;
	scanf("%lld %d", &N,&flag);
	long long i;
	int res = 0;
	int back;
	flag = flag == 1 ? 0 : 1;
	int ans;
	for (i = 1; i <N; i++)
	{
		if (i % 2 == 0)
		{
			if (flag2 == -1)
				flag2 = flag;
			if (flag2 == back)
			{
				res = 1;
				break;
			}
			ans = flag2;
		}
		if (i % 3 == 0)
		{
			if (flag3 == -1)
				flag3 = flag;
			if (flag3 == back)
			{
				res = 1;
				break;
			}
			ans = flag3;
		}
		else
			ans = flag;
		v.push_back(ans);
		back = flag;
		flag = flag == 1 ? 0 : 1;
	}
	if (res)
		printf("Love is open door");
	else
	{
		for (i = 0; i < v.size(); i++)
			printf("%d\n", v[i]);
	}

}
