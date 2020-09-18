#include <iostream>
using namespace std;
int N;
int chk[1000001];
int res = 0;
int main() {
	cin >> N;
	int i;
	int a, b, c;
	for (i=0;i<N;i++)
	{
		cin >> a >> b >> c;
		if (!chk[a]&&!chk[b]&&!chk[c])res++;
		chk[a] = chk[b] = chk[c] = 1;
	}
	cout << res;
}