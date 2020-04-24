#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include<deque>
#include <map>
using namespace std;
int arr[100001];
int N;
vector<int> v;
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int min_num = 2100000000;
	int i,j;
	int res = 0;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	int num;
	for (i = 1; i < N; i++)
	{
		num = arr[i] - arr[i - 1];
		v.push_back(num);
	}
	for (i = 1; i < v.size(); i++)
	{
		min_num = min(gcd(v[i], v[i - 1]), min_num);
	}
	for (i = 1; i < N; i++)
	{
		num = arr[i] - arr[i - 1];
		if (num != min_num)
		{
			res += (num / min_num) - 1;
		}
	}
	cout << res;
}

