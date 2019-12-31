#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int main()
{
	
	while (1)
	{
		int N;
		cin >> N;
		if (N == -1)
			break;
		vector<int> v;
		int sum = 0;
		for (int i = 1; i <= N / 2; i++)
		{
			if (N % i == 0)
			{
				v.push_back(i);
				sum += i;
			}
		}
		if (sum == N)
		{
			printf("%d =", N);
			for (int i = 0; i < v.size() - 1; i++)
			{
				printf(" %d +", v[i]);
			}
			printf(" %d\n", v[v.size() - 1]);
		}
		else
			printf("%d is NOT perfect.\n",N);
	}
}