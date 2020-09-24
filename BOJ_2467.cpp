#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
#define MAX 1e15
typedef long long int ll;
int N;
ll arr[100001];
ll res = MAX;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	int left = 0;
	int right = N - 1;
	ll res_left = arr[left];
	ll res_right = arr[right];
	ll s = arr[left] + arr[right];
	while (left < right)
	{
		if (abs(s) < res)
		{
			res = abs(s);
			res_left = arr[left];
			res_right = arr[right];
		}
		if (s < 0)
			left++;
		else
			right--;
		s = arr[left] + arr[right];
	}
	if (res_left)
	cout << res_left << " " << res_right;
}


