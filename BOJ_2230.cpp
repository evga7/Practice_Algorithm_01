#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N, M;
int arr[100001];
int res = 2100000000;
int main()
{
	int i;
	int num;
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int left = 0;
	int right = 1;
	int L = arr[left];
	int R = arr[right];
	int S = R - L;
	while (left <N&&right<N)
	{
		if (S >= M)
		{
            if (S==M)
            {
			    res = M;
			    break;
            }
            left++;
            res=min(res,S);
		}
		else
			right++;
		L = arr[left];
		R = arr[right];
		S = R - L;
	}
	cout << res;
}