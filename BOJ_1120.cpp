#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int res = 999999999;
	int cnt= 0;
	int i, j;
	for (i = 0; i <=str2.size() - str1.size(); i++)
	{
		cnt = 0;
		for (j = 0; j < str1.size(); j++)
		{
			if (str1[j] != str2[j + i])
				cnt++;
		}
		res = min(res, cnt);
	}

	printf("%d", res);
}
