#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
using namespace std;
priority_queue<int, vector<int>, greater<int>>pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int i;
	int num;
	int res = 0;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}
	while (pq.size() > 1)
	{
		num = pq.top();
		pq.pop();
		num += pq.top();
		pq.pop();
		res += num;
		pq.push(num);
	}
	cout << res;

}

