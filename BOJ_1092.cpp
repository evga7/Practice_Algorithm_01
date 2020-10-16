#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int N, M;
int num;
int i, j;
vector<int>crain;
vector<int>box;
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		crain.push_back(num);
	}
	cin >> M;
	for (i = 0; i < M; i++)
	{
		cin >> num;
		box.push_back(num);
	}
	sort(crain.begin(), crain.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());
	int cnt = 0;
	if (box[0] > crain[0])
	{
		cout << "-1";
		return 0;
	}
	else
	{
		while (box.size())
		{
			int idx = 0;
			for (i = 0; i < box.size(); i++)
			{
				if (idx == crain.size())
				{
					break;
				}
				if (crain[idx] >= box[i])
				{
					idx++;
					box.erase(box.begin() + i);
					i--;
				}
			}
			cnt++;
		}
		cout << cnt;
	}

}





