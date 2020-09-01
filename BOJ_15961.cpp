#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
using namespace std;
int N, D, K, C;
vector<int>v;
deque<int>dq;
int res = 0;
int cnt = 0;
int chk[3001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> D >> K >> C;
	int i;
	v.resize(N + 1);
	for (i =0; i <N; i++)
		cin >> v[i];
	for (i = 0; i <N+K-1; i++)
	{
		int idx = i % N;
		int num = v[idx];
		dq.push_back(num);
		if (!chk[num])
		{
			cnt++;
		}
		chk[num]++;
		if (dq.size() == K)
		{
			if (!chk[C])
				res = max(cnt + 1, res);
			else
				res = max(cnt, res);
			int temp = dq.front();
			dq.pop_front();
			chk[temp]--;
			if (!chk[temp])
				cnt--;
		}
	}

	cout << res;
}
