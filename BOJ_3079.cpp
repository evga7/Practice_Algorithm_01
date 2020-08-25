#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
int N, M;
vector<long long>v;
long long res;
int main()
{
	cin >> N >> M;
	int i;
	long long num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	long long left = 0;
	long long right = M * v[N - 1];
    res=right;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (i=0;i<N;i++)
		{
			sum += mid / v[i];
		}
		if (sum < M)
		{
			left = mid + 1;
		}
		else
		{
			res = min(res,mid);
			right = mid - 1;
		}
	}
	cout << res;
}