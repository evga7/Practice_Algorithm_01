#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
int main()
{
	string str;
	string bomb;
	cin >> str >> bomb;
	int i, j;
	char res[1000001];
	int idx = 0;
	int Size;
	for (i = 0; i < str.size(); i++)
	{
		res[idx++] = str[i];
		Size = bomb.size() - 1;
		if (str[i] == bomb[Size])
		{
			int flag = 1;
			int cnt = 0;
			int len = idx - bomb.size();
			for (j = idx - 1; j >= len; j--)
			{
				if (res[j] != bomb[Size--])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				idx -= bomb.size();
			}
		}
	}
	if (idx == 0)
		printf("FRULA");
	else
	{
		for (i = 0; i < idx; i++)
			printf("%c", res[i]);
	}
}
