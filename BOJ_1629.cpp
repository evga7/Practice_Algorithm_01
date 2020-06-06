#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
using namespace std;
long long A, B, C;
long long divide(long long A, long long B)
{
	if (B == 0)
		return 1;
	else if (B == 1)
		return A;
	else if (B % 2)
		return divide(A, B -1)*A;
	long long half = divide(A, B / 2);
	half %= C;
	return (half * half) % C;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> C;
	int i;
	cout << divide(A, B)%C;
}

