#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 987654321
int N, M;
vector<int>v;
typedef long long int ll;
ll res = 1e15;
int chk(int mid)
{
	int cnt=1;
	int i;
	int temp = mid;
	for (i = 0; i < N; i++)
	{
		if (temp - v[i] >=0)
		{
			temp -= v[i];
		}
		else
		{
			if (v[i] > mid) return 0;
			temp = mid - v[i];
			cnt++;
		}
	}
	return cnt;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int i;
	cin >> N >> M;
	int num;
	int max_num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		max_num = max(max_num, v[i]);
	}
	ll low = max_num;
	ll high = MAX;
	while (low<=high)
	{
		ll mid = low + high >> 1;
		int ck = chk(mid);
		if (ck >M)
		{
			low=mid+1;
		}
		else if (ck <= M)
		{
			high = mid - 1;
			//if (ck==M)
			res = min(res, mid);
		}
	}
	cout << res;
}
