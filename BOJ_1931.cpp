#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef struct T {
	int S, E;
}T;
bool cmp(const T &a, const T &b)
{
	if (a.E == b.E) return a.S < b.S;
	return a.E < b.E;
}
T arr[100001];
int main()
{
	int N;
	int i, j;
	int a, b;
	cin >> N;
	int res = 0;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		arr[i].S = a, arr[i].E = b;
	}
	sort(arr, arr + N, cmp);
	long long cnt = 0;
	long long pos = 0;
	for (i = 0; i < N; i++)
	{
		if (arr[i].S >= pos)
		{
			pos = arr[i].E;
			cnt++;
		}
	}
	cout << cnt;
}
