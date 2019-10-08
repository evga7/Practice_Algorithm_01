#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int res = 0;
	while (1)
	{
		if (K == 0)
			break;
		if (N/2 >= M)
			N--;
		else
			M--;
		K--;
	}

	cout << min(N/2,M);
}
