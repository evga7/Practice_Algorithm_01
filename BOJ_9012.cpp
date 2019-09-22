#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include <stack>
string str;

int main()
{
	int N;
	scanf("%d", &N);
	int i;
	int flag = 0;
	for (i = 0; i < N; i++)
	{
		stack<char>s;
		cin >> str;
		flag = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(')
				s.push('(');
			else
			{
				if (!s.empty()&&s.top() == '(')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag||!s.empty())
			printf("NO\n");
		else
			printf("YES\n");
	}

}