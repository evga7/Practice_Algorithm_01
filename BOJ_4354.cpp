#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getpi(string s)
{
	int size = s.size();
	int i, j = 0;
	vector<int> pi(size, 0);
	for (i = 1; i < size; i++)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = pi[j - 1];
		}
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1)
	{
		string str;
		cin >> str;
		if (str[0] == '.' && str.size() == 1)
			break;
		int i;
		vector<int>ans = getpi(str);
		int size = ans.size() - 1;
		int res = str.size() / (str.size() - ans[size]);
		
		if (ans[size] == 0 || str.size() % res)
			cout << "1\n";
		else
			cout << res << '\n';

	}
}

