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
vector<string>v;
bool solve()
{
	int i;
	int idx = 0;
	while(idx<str.size())
	{
		string temp = str.substr(idx, 2);
		string temp2 = str.substr(idx, 3);
		if (temp == "pi" || temp == "ka")
			idx += 2;
		else if (temp2 == "chu")
			idx += 3;
		else
			return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	v.push_back("pi");
	v.push_back("ka");
	v.push_back("chu");
	int i;
	cin >> str;
	if (solve())
		cout << "YES";
	else
		cout << "NO";

}