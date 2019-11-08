#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int i;
	int cnt = 0;
	int res = 0;
	int res2 = 0;
	char back = '2';
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '0')
		{
			if (back == '2')
				cnt++;
			else if (back != '0')
				cnt++;
		}
		else
		{
			res += cnt;
			cnt = 0;
		}
		back = str[i];
	}
	res += cnt;
	back = '2';
	cnt = 0;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '1')
		{
			if (back == '2')
				cnt++;
			else if (back != '1')
				cnt++;
		}
		else
		{
			res2 += cnt;
			cnt = 0;
		}
		back = str[i];
	}
	res2 += cnt;
	printf("%d", min(res,res2));
}