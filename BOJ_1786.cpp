#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <map>
using namespace std;
vector<int> res;
int cnt = 0;
vector<int> maketable(string s)
{
	int size = s.size();
	int j = 0;
	vector<int> v(size, 0);
	for (int i = 1; i < size; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = v[j - 1];
		if (s[i] == s[j])
			v[i] = ++j;
	}
	return v;
}
void KMP(string T,string P)
{
	vector<int> v = maketable(P);
	int size = T.size();
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		while (j > 0 && T[i] !=P[j])
			j = v[j - 1];
		if (T[i] == P[j])
		{
			if (j == P.size() - 1)
			{
				cnt++;
				res.push_back(i - P.size() + 2);
				j = v[j];
			}
			else
				j++;
		}
	}
}
int main()
{
	string T, P;
	getline(cin, T);
	getline(cin, P);
	KMP(T, P);
	printf("%d\n", cnt);
	for (auto a : res)
		printf("%d\n", a);

}