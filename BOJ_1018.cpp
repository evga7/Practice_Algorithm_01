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
char arr[51][51];
int main()
{
	int N, M;
	cin >> N >> M;
	int i, j,q,w;
	int res = 2100000000;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> arr[i][j];
		
	}
	for (i = 0; i < N - 7; i++)
	{
		for (j = 0; j < M - 7; j++)
		{
			int a, b;
			a = b = 0;
			char temp = arr[i][j];
			for (q=i;q<i+8;q++)
				for (w = j; w < j + 8; w++)
				{
					if ((q + w) % 2 == 0)
					{
						if (arr[q][w] != temp)
							a++;
						else
							b++;
					}
					else if ((q + w) % 2 == 1)
					{
						if (arr[q][w] !=temp)
							b++;
						else
							a++;
					}
				}
			res = min({ a,b,res });
		}
	}
	cout << res;
}

