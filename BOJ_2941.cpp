#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main()
{
	string str;
	vector<string>v = { {"c="}, { "c-" }, { "dz=" }, { "d-" }, { "lj" }, { "nj" }, { "s=" }, { "z=" } };
	cin >> str;
	int i;
	int len = str.size();
	int cnt = 0;
	for (i = 0; i < len; i++)
	{
		string temp="";
		string temp2="";
		if (i + 1 <= len-1)
		{
			temp = temp +str[i] + str[i + 1];
		}
		if (i + 2 <= len-1)
		{
			temp2 = temp2+str[i] + str[i + 1] + str[i + 2];
		}

		for (auto num : v)
		{
			if (!num.compare(temp))
			{
				i++;
				break;
			}
			if (!num.compare(temp2))
			{
				i += 2;
				break;
			}
		}
		cnt++;
	}
	printf("%d", cnt);
}