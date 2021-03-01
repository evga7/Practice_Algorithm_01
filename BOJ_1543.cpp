#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
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
string str;
string str2;
bool is_inside(int x, int y)
{		
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	getline(cin, str);
	getline(cin, str2);
	int len = str.size();
	int len2 = str2.size();
	int idx = 0;
	while (1)
	{
		if (idx + len2 >len)break;
		string temp;
		temp = str.substr(idx, len2);
		if (temp == str2)
		{
			res++;
			idx += len2;
		}
		else
			idx++;
	}
	cout << res;
}
