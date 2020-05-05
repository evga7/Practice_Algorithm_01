#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
using namespace std;
int N;
priority_queue <int> maxq;
priority_queue <int,vector<int>,greater<int>> minq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int i;
	int num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		if (minq.size() == maxq.size())
			maxq.push(num);
		else
			minq.push(num);
		if (!maxq.empty() &&!minq.empty()&& minq.top() < maxq.top())
		{
			int a, b;
			a = minq.top();
			b = maxq.top();
			minq.pop();
			maxq.pop();
			maxq.push(a);
			minq.push(b);
		}
		cout << maxq.top() << "\n";
	}
}

