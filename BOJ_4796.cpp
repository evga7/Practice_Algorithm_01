#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int L, P, V;
int num;
int i, j;
vector<int>v;
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	int idx = 1;
	while (1)
	{
		cin >> L >> P >> V;
		if (!L && !P && !V)
			return 0;
		int res = V / P * L;
		if (V % P > L)
			res += L;
		else
			res += V % P;
		cout << "Case " << idx++ <<": "<<res<<"\n";
	}
}