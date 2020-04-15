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
int arr[4];
int main()
{
	int i;
	int N;
	arr[1] = 1;
	int res = 1;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (arr[a] || arr[b])
		{
			swap(arr[a], arr[b]);
			if (arr[a])
				res = a;
			else
				res = b;
		}
	}
	cout << res;
}

