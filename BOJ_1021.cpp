#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
deque<int> dq;
int arr[51];
int main()
{
	int N, M;
	deque<int>::iterator it;
	cin >> N >> M;
	int i;
	int cnt = 0;
	int res = 0;
	for (i = 1; i <=N; i++)
	{
		dq.push_back(i);
	}
	for (i = 0; i < M; i++)
	{
		scanf("%d", &arr[i]);
	}
	while (1)
	{
		if (cnt == M)
			break;
		int index = 1;
		for (it = dq.begin(); it < dq.end(); it++)
		{
			if (*it == arr[cnt])
				break;
			index++;
		}
		int left = index-1;
		int size = dq.size();
		int right= abs(index - size-1);
		if (left <right)
		{
			while (1)
			{
				if (dq.front() == arr[cnt])
				{
					dq.pop_front();
					cnt++;
					break;
				}
				dq.push_back(dq.front());
				dq.pop_front();
				res++;
			}
		}
		else
		{
			while (1)
			{
				if (dq.front() == arr[cnt])
				{
					dq.pop_front();
					cnt++;
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				res++;
			}
		}
	}
	cout << res;
}

