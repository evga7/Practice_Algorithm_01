#include <bits/stdc++.h>
#define MAX 1000000001
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int dx[4] = { 0,-1,0,1 };
int dy[4] = {-1,0,1,0 };
int N,M;
string str;
pi solve(int idx)
{
	int i;
	int cnt = 0;
	for (i = idx; i >= 0; i--)
	{
		if (str[i] == '(')
			break;
		else if (str[i] == ')')
		{
			pi temp = solve(i-1);
			i = temp.first;
			cnt += (str[i] - '0') * temp.second;
		}
		else
			cnt++;
	}
	return { i - 1,cnt };
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	cout<<solve(str.size()-1).second;

}


