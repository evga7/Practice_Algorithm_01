#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
using namespace std;
int N;
queue<int> q;
stack<int> s;
int arr[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	string str = "";
	int i;
	int num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		q.push(num);
	}
	int flag = 0;
	for (i = 1; i <= N; i++)
	{
		s.push(i);
		str += '+';
		while (!s.empty())
		{
			if (s.top() == q.front())
			{
				s.pop();
				q.pop();
				str += '-';
			}
			else
				break;
		}
		if (!q.empty()&&i > q.front())
		{
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		for (i = 0; i < str.size(); i++)
			cout << str[i] << '\n';
	}
	else
		cout << "NO";
}

