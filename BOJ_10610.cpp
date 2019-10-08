#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(char a, char b)
{
	return a > b;
}
int main()
{
	string str;
	int sum = 0;
	cin >> str;
	int i;
	int zero = 0;
	for (i = 0; i < str.size(); i++)
	{
		sum += str[i] - '0';
		if (str[i] == '0')
			zero = 1;
	}
	if (sum % 3 != 0 || !zero)
		printf("-1");
	else
	{
		sort(str.begin(), str.end(),cmp);
		cout << str;
	}
}
