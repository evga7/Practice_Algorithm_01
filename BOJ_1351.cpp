#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
map<long long, long long>m;
long long N, P, Q;
long long solve(long long N)
{
	if (m[N])
	{
		return m[N];
	}
	else
		return m[N] = solve(N / P) + solve(N / Q);
}
int main()
{
	m[0] = 1;
	scanf("%lld %lld %lld", &N, &P, &Q);
	solve(N);
	printf("%lld", m[N]);

}