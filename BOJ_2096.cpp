#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 987654321
int N;
vector<int>minv;
vector<int>maxv;
vector<int>v;
int main() {
	int i,j;
	cin >> N;
	int a, b, c;
	int q, w, e;
	cin >> a >> b >> c;
	minv.resize(3);
	maxv.resize(3);
	v.resize(3);
	minv[0] = maxv[0]=a;
	minv[1] = maxv[1] = b;
	minv[2] = maxv[2] = c;
	for (i = 1; i < N; i++)
	{
		cin >> a >> b >> c;
		q = minv[0]; w = minv[1]; e = minv[2];
		minv[0] = a + min(q, w);
		minv[1] = b + min({ q,w,e });
		minv[2] = c + min(w, e);
		q = maxv[0]; w = maxv[1]; e = maxv[2];
		maxv[0] = a + max(q, w);
		maxv[1] = b + max({ q,w,e });
		maxv[2] = c + max(w, e);
	}
	int res1 = max({ maxv[0],maxv[1],maxv[2] });
	int res2 = min({ minv[0],minv[1],minv[2] });
	cout << res1 << " " << res2;
}