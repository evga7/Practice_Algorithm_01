#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <map>
using namespace std;
int arr[101][101];
int main()
{
	int res = 0;
	int x1, y1, x2, y2;
	int i, j, k;
	for (i = 0; i < 4; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (j = x1; j < x2; j++)
			for (k = y1; k < y2; k++)
				arr[j][k] = 1;
	}
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			if (arr[i][j])
				res++;
	cout << res;
}