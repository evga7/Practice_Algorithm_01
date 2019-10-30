#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N;
int a, b;
int main()
{
	int N, M;
	cin >> N >> M;
	int i;
	int res = 0;
	int Min1, Min2;
	Min1 = Min2 = 999999999;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		Min1 = min(Min1, a);
		Min2 = min(Min2, b);
	}
	
	while (N > 0)
	{
        if (N>=6)
        {
		if (Min1 > Min2*6)
		{
			res += Min2 * 6;
			N-=6;
		}
		else
		{
			res += Min1;
			N -= 6;
		}
        }
        else
        {
            res+=min(Min1,Min2*N);
            break;
        }
	}
	cout << res;
}