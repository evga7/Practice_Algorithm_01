#include <cstring> 
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#define MAX 987654321
typedef long long int ll;
using namespace std;
int N;
string S;
stack<int>s;
ll res = 0;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int i;
	cin >> N;
	int num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 0)
		{
			if (s.size() > 0)
				s.pop();
		}
		else
			s.push(num);
	}
	while (!s.empty())
	{
		res += s.top();
		s.pop();
	}
	cout << res;
}