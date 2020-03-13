#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int arr[4000001];
int N;
vector<int> prime;
void e()
{
	int i, j;
	for (i = 2; i*i <= N; i++)
	{
		if (arr[i])
			continue;
		for (j = i * i; j <=N; j+=i)
		{
			arr[j] = 1;
		}
	}
	for (i = 2; i <= N; i++)
		if (arr[i] == 0)
			prime.push_back(i);
}
int main()
{
	cin >> N;
	e();
	int i,j;
	int res = 0;
	for (i = 0; i < prime.size(); i++)
	{
		int sum = 0;
		for (j = i; j < prime.size(); j++)
		{
			sum += prime[j];
			if (sum > N)
				break;
			if (sum == N)
			{
				res++;
				break;
			}
		}
	}
	cout << res;
}
