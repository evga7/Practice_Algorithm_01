#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 987654321
int N, T;
vector<int>v;
vector<int>res;
vector<int>temp;
bool chk(int mid)
{
	int i, j;
	int cnt = 0;
	temp = v;
	for (i = 0; i < N-1; i++)
	{
		int sub = temp[i + 1] - temp[i];
		if (sub > mid)
		{
			cnt += temp[i + 1] - (temp[i] + mid);
			temp[i+1] = temp[i]+mid;
		}
	}
	for (i = N - 1; i > 0; i--)
	{
		int sub = temp[i - 1] - temp[i];
		if (sub > mid)
		{
			cnt += temp[i - 1] - (temp[i] + mid);
			temp[i-1] = temp[i]+mid;
		}
	}
	if (cnt <= T)
		return true;
	return false;
}
int main() {
	cin >> N >> T;
	int i, j;
	int num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	int low = 0;
	int high = 1e9;
	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (chk(mid))
		{
			high = mid-1;
			res = temp;
		}
		else
		{
			low = mid+1;
		}
	}
	for (i = 0; i < N; i++)
		cout << res[i]<<" ";
}