#include <bits/stdc++.h>
#define MAX 2147483647
#define MIN -2147483,648
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
typedef vector<pi> vec2;
typedef queue<pi> que;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res;
int L, P;
string str;
bool is_inside(int x, int y)
{
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}

bool is_palindrome()
{
	int left = 0;
	int right = str.size() - 1;
	while (left <= right)
	{
		if (str[left++] != str[right--])return false;
	}
	return true;
}
bool solve(int left,int right,int chk)
{
	if (left > right)return true;
	if (str[left] == str[right])return solve(left + 1, right - 1, chk);
	else if (chk)return max(solve(left + 1, right, 0), solve(left, right - 1, 0));
	return false;
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	int N;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> str;
		if (is_palindrome())cout << 0;
		else if (solve(0,str.size()-1,1))cout << 1;
		else
			cout << 2;
		cout << "\n";
	}
}
