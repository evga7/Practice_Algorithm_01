2 1 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
long long A, B, V;
long long res;
void sol()
{
	int temp = (V-A) % (A - B);
	if (temp == 0)
		res = (V-A) / (A - B);
	else
		res = (V-A) / (A - B)+1;
	res++;
}
int main()
{
	cin >> A >> B >> V;
	sol();
	cout << res;
}


