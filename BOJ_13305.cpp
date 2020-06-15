#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
using namespace std;
int N;
vector<int>v;
long long pre=2100000000;
long long res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int i;
	long long num;
	
	for (i = 0; i < N - 1; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (i = 0; i < N-1; i++)
	{
		cin >> num;
		pre = min(pre, num);
		res += pre * v[i];
	}
	cout << res;
}

