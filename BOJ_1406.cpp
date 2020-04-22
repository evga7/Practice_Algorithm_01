#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


list<char> l;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	list<char>::iterator it;
	string str;
	int M;
	int i;
	cin >> str>>M;
	for (i = 0; i < str.size(); i++)
		l.push_back(str[i]);
	it = l.end();
	while (M--)
	{
		char op;
		cin >> op;
		if (op == 'L')
		{
			if (it != l.begin())
			{
				it--;
			}
		}
		else if (op == 'D')
		{
			if (it != l.end())
			{
				it++;
			}
		}
		else if (op == 'B')
		{
			if (it != l.begin())
			{
				
				it=l.erase(--it);
			}
		}
		else
		{
			char s;
			cin >> s;
			l.insert(it, s);
		}
	}
	for (it = l.begin(); it != l.end(); it++)
		cout << *it;

	
}

