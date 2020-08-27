#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
/*
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
*/
using namespace std;
int res = 0;
int G, P;
vector<int> v;
int parent[1000001];
int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		parent[x] = y;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> G >> P;
	int i,j;
	int num;
	for (i = 1; i <=G; i++)
		parent[i] = i;
	for (i = 0; i < P; i++)
	{
		cin >> num;
		v.push_back(num);
		int x = find(num);
		if (x == 0)
			break;
		else
		{
			uni(x, x - 1);
			res++;
		}
	}
	cout << res;
}