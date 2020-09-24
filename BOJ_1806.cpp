#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 987654321
int N, M;
int arr[100001];
int res = MAX;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	int i, num;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int left = 0;
	int right = 0;
	int s = arr[left];
	while(left<=right&&right<N)
	{
		if (s <= M)
		{
			if (s == M)
			{
				res = min(res, right - left);
			}
			s+=arr[++right];
		}
		else
		{
			res = min(res, right - left);
			s -= arr[left++];
		}
	}
	if (res == MAX)
		cout << 0;
	else
		cout << res+1;
}


