#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
string str;
string str2;
string tmp2;
int res = 100001;
int N;
void sol(string &tmp, int start, int cnt)
{

	if (start == N - 1)
	{
		int i;
		if (tmp[start - 1] == str2[start - 1] && tmp[start] == str2[start])
			res = min(cnt, res);
		for (i = start - 1; i <= start; i++)
			if (tmp[i] == '1')tmp[i] = '0';
			else
				tmp[i] = '1';
		if (tmp[start - 1] == str2[start - 1] && tmp[start] == str2[start])
			res = min(cnt + 1, res);
		return;
	}

	if (tmp[start - 1] == str2[start - 1])
		sol(tmp, start + 1, cnt);
	int i;
	for (i = start - 1; i <= start+1; i++)
		if (tmp[i] == '1')tmp[i] = '0';
		else
			tmp[i] = '1';
	if (tmp[start - 1] == str2[start - 1])
		sol(tmp, start + 1, cnt + 1);

}
int main()
{
	int i;
	cin >> N >> str >> str2;
	 tmp2 = str;
	for (i = 0; i <= 1; i++)
		if (tmp2[i] == '1')tmp2[i] = '0';
		else
			tmp2[i] = '1';
	sol(str, 1, 0);
	sol(tmp2, 1, 1);
	if (res == 100001)
		cout << "-1";
	else

	cout << res;
}


