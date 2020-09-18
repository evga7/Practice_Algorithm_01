#include <iostream>
using namespace std;
typedef long long ll;
ll A, B;
ll solve(ll num)
{
	num++;
	ll num2 = num, target = 1, ret = 0;
	while (num2)
	{
		if (num & target)ret += num % (target + ((num - num % (target * 2)) / 2));
		else ret += (num - num % (target * 2)) / 2;
		target <<= 1;
		num2 >>=1;
	}
	return ret;

}
int main() {
	cin >> A >> B;
	cout << solve(B) - solve(A - 1);
}