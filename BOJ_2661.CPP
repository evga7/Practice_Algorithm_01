#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include<deque>
using namespace std;
int N;
bool flag = false;
bool chk(string s,int len)
{
	int i;
	for (i = 1; i <= len / 2; i++)
	{
		string a, b;
		a = s.substr(len-i, i);
		b = s.substr(len - i * 2, i);
		if (a == b)
		{
			return false;
		}
	}
	return true;
}
void solve(int len, string s)
{
	if (flag)return;
	else
	{
		if (!chk(s, len)) return;
		if (len == N)
		{
			cout << s << endl;
			flag = true;
			return;
		}
		solve(len + 1, s + '1');
		solve(len + 1, s + '2');
		solve(len + 1, s + '3');
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	solve(1, "1");
}

