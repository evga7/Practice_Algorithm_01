#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int A, B, N, M;
queue<pair<int,int>> q;
int res = 2100000000;
int arr[100001];
void solve()
{
	while (!q.empty())
	{
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (n == M)
			res = cnt;
		if (n + 1 <= 100000 && !arr[n + 1]) {
			arr[n + 1] = 1;
			q.push(make_pair(n + 1, cnt + 1));
		}
		if (n - 1 >=0 && !arr[n - 1]) {
			arr[n - 1] = 1;
			q.push(make_pair(n - 1, cnt + 1));
		}
		if (n + A <= 100000&&!arr[n+A]) {
			arr[n + A] = 1;
			q.push(make_pair(n + A, cnt + 1)); 
		}
		if (n - A >=0 && !arr[n - A]) {
			arr[n - A] = 1;
			q.push(make_pair(n - A, cnt + 1));
		}
		if (n * A <= 100000&&!arr[n * A]) {
			arr[n * A] = 1;
			q.push(make_pair(n * A, cnt + 1));
		}
		if (n + B <=100000 && !arr[n + B]) {\
			arr[n + B] = 1;
			q.push(make_pair(n + B, cnt + 1)); 
		}
		if (n - B >=0 && !arr[n - B]) {
			arr[n - B] = 1;
			q.push(make_pair(n - B, cnt + 1));
		}
		if (n * B <= 100000&& !arr[n * B]) {\
			arr[n * B] = 1;
			q.push(make_pair(n * B, cnt + 1));
		}
	}
	return;
}
int main()
{
	scanf("%d %d %d %d", &A, &B, &N, &M);
	q.push(make_pair(N, 0));
	arr[N] = 1;
	solve();
	printf("%d", res);
}
