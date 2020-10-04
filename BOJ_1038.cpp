#include <iostream>
#include <cstring> 
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#define MAX 987654321
using namespace std;
typedef long long int ll;
int N;
ll res[1000001];
int cnt = 0;
void solve(ll num)
{
	ll a = num % 10, b = num * 10;
	int i;
	for (i = 0; i < a; i++)
	{
		res[cnt++] = b + i;
		solve(b + i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < 10; i++)
	{
		res[cnt++] = i;
		solve(i);
	}
	sort(res, res + cnt);
	if (N >=cnt)
		cout << -1;
	else
	cout << res[N];

}
