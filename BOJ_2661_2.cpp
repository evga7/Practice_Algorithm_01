#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res = 0;
int D, K, C;
int flag;
void solve(int cnt, string str)
{
	if (flag)return;
	int i;
	int s = str.size();
	for (i = 1; i <= s / 2; i++)
	{
		string s1 = str.substr(s - i, i);
		string s2 = str.substr(s - i * 2, i);
		if (s1 == s2) return;
	}
	if (cnt == N)
	{
		cout << str;
		flag = 1;
		return;
	}
	solve(cnt + 1, str + '1');
	solve(cnt + 1, str + '2');
	solve(cnt + 1, str + '3');
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	solve(0, "");

}