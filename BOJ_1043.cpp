#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
using namespace std;
int N, M,T;
int i, j,k;
vector<int> knownPeople;
vector<vector<int>> People(51);
int arr[51];
int res = 0;

void in_it()
{
	for (i=1;i<=N;i++)
		arr[i] = i;
}
int find(int x)
{
	if (x == arr[x])
		return x;
	else
	{
		int p = find(arr[x]);
		arr[x] = p;
		return p;
	}
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		arr[y] = x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M>>T;
	int num;
	in_it();
	for (i = 0; i < T; i++)
	{
		cin >> num;
		knownPeople.push_back(num);
	}
	for (i = 0; i < M; i++)
	{
		cin >> num;
		int prev;
		int num2;
		for (j = 0; j < num; j++)
		{
			if (j > 0)
			{
				prev = num2;
				cin >> num2;
				uni(prev, num2);
			}
			else
				cin >> num2;
			People[i].push_back(num2);
		}
	}
	for (auto& v : People)
	{
		bool flag = false;
		for (auto& v2 : v)
		{
			if (flag)break;
			for (auto& v3 : knownPeople)
			{
				if (find(v2) == find(v3))
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
			M--;
	}
	cout << M;
}

