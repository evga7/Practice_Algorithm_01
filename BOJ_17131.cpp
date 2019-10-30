#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
long long Mod = 10e8 + 7;
int main()
{
	long long A, X;
	long long res = 1;
	cin >> A >> X;
	long long i;
	A = A %Mod;
	while (X > 0)
	{
		if(X&1)
			res=(res* A)%Mod;
		X >>=1;
		A = (A * A)%Mod;
	}
	cout << res;
}