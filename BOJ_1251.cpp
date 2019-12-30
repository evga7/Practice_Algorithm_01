#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int len;
string res;
void go(string str, int Start, int Second)
{
	string A, B, C;
	int i;
	A = B = C = "";
	for (i = 0; i <= Start; i++)
	{
		A = A + str[i];
	}
	for (i = Start + 1; i <= Second; i++)
	{
		B = B + str[i];
	}
	for (i = Second + 1; i < len; i++)
	{
		C = C + str[i];
	}
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	reverse(C.begin(), C.end());
	string D = "";
	D = A + B + C;
	if (res == "")
		res = D;
	else
	{
		if (res > D)
			res = D;
	}

}
int main()
{
	string str;
	cin >> str;
	int i, j;
	res = "";
	len = str.size();
	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len - 1; j++)
		{
			if (i >= j)
				continue;
			string temp = str;
			go(temp, i, j);
		}
	}
	cout << res;
}