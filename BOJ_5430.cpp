#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include<deque>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int i, N;
	while (T--)
	{
		string p;
		cin >> p >> N;
		int num=0;
		int flag = 0;
		string str;
		cin >> str;
		int R_cnt = 0;
		deque<int>dq;
		int len = str.size();
		for (i =1; i < len; i++)
		{
			if (str[i] == ','||str[i]==']')
			{
				if (num!=0)
				dq.push_back(num);
				num = 0;
			}
			if (num > 0)
				num = num * 10 + (str[i] - '0');
			else
				num = str[i] -'0';
		}
		len = p.size();
		for (i = 0; i <len; i++)
		{
			if (p[i] == 'R')
			{
				R_cnt++;
			}
			else
			{
				if (dq.empty())
				{
					flag = 1;
					break;
				}
				else
				{
					if (R_cnt > 0 && R_cnt % 2)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
		}
		if (flag)
			cout << "error\n";
		else if (dq.empty())
		{
			cout << "[]\n";
		}
		else
		{
			cout << '[';
			len = dq.size();
			if (R_cnt % 2 == 1)
			{
				for (i=len-1;i>0;i--)

					cout << dq[i] << ',';
				cout << dq[i] << "]\n";
			}
			else
			{
				for (i = 0; i < len - 1; i++)
					cout << dq[i] << ',';
				cout << dq[i] << "]\n";
			}
		}

	}

}

