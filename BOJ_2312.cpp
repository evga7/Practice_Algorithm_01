#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
int arr[100001];
void e()
{
	int i, j;
	for (i = 2; i*i <= 100000; i++)
	{
		if (!arr[i])
		{
			for (j = i + i; j <= 100000; j += i)
			{
				arr[j] = 1;
			}
		}
	}
}
vector<int>v;
int main()
{
	int N, M;
	int i, j;
	scanf("%d", &N);
	e();
	for (i = 2; i <= 100000; i++)
		if (!arr[i])
			v.push_back(i);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &M);
		int cnt = 0;
		for (j = 0; j < v.size(); j++)
		{
			cnt = 0;
			while(M%v[j]==0)
			{
				M /= v[j];
				cnt++;
			}
			if (cnt >=1)
				printf("%d %d\n", v[j], cnt);
		}
	}
}
