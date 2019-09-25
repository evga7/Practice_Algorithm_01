#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
int res = 0;
int num[10];
int main()
{
	string str;
	cin >> str;
	int i;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '9')
			num[6]++;
		else
		num[str[i] - '0']++;
	}
	if (num[6] % 2 == 0)
		num[6] /= 2;
	else
		num[6] = (num[6] / 2) + 1;
	for (i = 0; i < 10; i++)
	{
		res = max(res, num[i]);
	}
	printf("%d", res);
}
