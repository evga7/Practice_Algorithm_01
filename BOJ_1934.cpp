#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int GCD(int a,int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}
int main()
{
	int N;
	cin >>N;
	while (N--)
	{
		int a, b;
		int c;
		cin >> a>>b;
		c = GCD(a, b);
		cout << a*b/c<<"\n";
	}
}


