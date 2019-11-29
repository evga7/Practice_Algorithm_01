#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
vector<string>str;
int alpha[27];
int res = 0;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		str.push_back(temp);
		int mul = 1;
		for (j = temp.size()-1; j >=0; j--)
		{
			
			alpha[temp[j]-'A' ] += mul;
			mul *= 10;
		}
	}
	sort(alpha, alpha + 26,cmp);
	int num = 9;
	for (i = 0; i < 26; i++)
	{
		if (alpha[i] != 0)
		{
			res += alpha[i] * num;
			num--;
		}
	}
	printf("%d", res);
}