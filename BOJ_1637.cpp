#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
int N;
#define MAX 2147483647
vector<long long> A;
vector<long long> B;
vector<long long> C;
long long solve(long long mid)
{
	int i;
	long long cnt = 0;

	for (i = 0; i < N; i++)
	{
		if (A[i] <= mid)
		{
			cnt += (min(B[i], mid)-A[i]) / C[i] + 1;
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	cin >> N;
	long long a, b, c;

	for (i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
	}
	long long left=1;
	long long right=MAX;
	while (left <right)
	{
		long long mid = (left + right) / 2;
		if (solve(mid)&1)
		{
			right = mid;
		}
		else
			left = mid+1;
	}
	if (left == MAX)
		cout << "NOTHING";
	else
		cout << left << " " << solve(left) - solve(left - 1);
}

