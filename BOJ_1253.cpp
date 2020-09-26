#include <string> 
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int N;
int arr[2001];
int res = 0;
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (i = 0; i < N; i++)
	{
		int num = arr[i];
		int left = 0;
		int right = N-1;
		while (left < right)
		{
			if (left == i)
				left++;
			else if (right == i)
				right--;
			if (left >=right)
				break;
			int sum = arr[left] + arr[right];
			if (sum <= num)
			{
				if (sum == num)
				{
					res++;
					break;
				}
				left++;
			}
			else
				right--;
		}
	}
	cout << res;
}