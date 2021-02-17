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
vector<int>v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	int i;
	string temp = "";
	int op = 0;
	for (i = 0; i <= str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (op)
			{
				res -= stoi(temp);
			}
			else
				res += stoi(temp);
			temp = "";
			if (str[i] == '-')
				op = 1;
		}
		else
			temp += str[i];
	}
	cout << res;
}