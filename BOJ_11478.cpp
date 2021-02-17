#include <bits/stdc++.h>
#include <unordered_map>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int N, M;
int num;
string str;
int res;
set<string>s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,j;
	cin >> str;
	for (i = 1; i <=str.size(); i++)
	{
		for (j = 0; j <=str.size()-i; j++)
		{
			s.insert(str.substr(j, i));
		}
	}
	cout << s.size();
}