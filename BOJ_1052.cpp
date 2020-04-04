#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
int N, K;
int res = 0;
void solve()
{
	int M = N;
	while (1)
	{
		int cnt = 0;
		int temp = M;
		while (temp > 0)
		{
			if (temp % 2 == 1) cnt++;
			temp /= 2;
		}
		if (cnt <= K)break;
		M++;
	}
	printf("%d", M - N);
}
int main()
{
	scanf("%d %d", &N, &K);
	int i;
	solve();

}


