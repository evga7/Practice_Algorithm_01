#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
#include <list>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string str;

	while (N--)
	{
		cin >> str;
		int i,j;
		int index = 0;
		int size = 0;
		list<char> l;
		list<char>::iterator it;
		it = l.begin();
		for (i = 0; i < str.size(); i++)
		{
			if (str[i] == '<')
			{
				if (it!=l.begin())
				{
					it--;
				}
			}
			else if (str[i] == '>')
			{
				if (it!=l.end())
				{
					it++;
				}
			}
			else if (str[i] == '-')
			{
				if (it != l.begin())
				{
					it = l.erase(--it);
				}
			}
			else
			{
				l.insert(it, str[i]);
			}
		}

		for (it = l.begin(); it != l.end(); it++)
			cout << *it;
		cout << endl;

	}
}

