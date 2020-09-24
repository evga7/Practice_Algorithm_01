#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 987654321
int N, H;
int hinder[200001];
int hinder2[200001];
int res=MAX;
int cnt = 1;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int i;
	cin >> N >> H;
	for (i = 0; i <N/2; i++)
		cin >> hinder[i]>>hinder2[i];
	sort(hinder, hinder + (N / 2));
	sort(hinder2, hinder2 + (N / 2));
	for (i = 1; i <= H; i++)
	{
		int val = lower_bound(hinder, hinder + (N / 2), i) - hinder;
		val += upper_bound(hinder2, hinder2 + (N / 2), H - i) - hinder2;
		val = N - val;
		if (res == val)
			cnt++;
		else if (res>val)
		{
			res = min(res, val);
			cnt = 1;
		}
	}cout << res << " " << cnt<<"\n";
}
