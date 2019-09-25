#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
string str;
long long POW(int k)
{
	if (k == 0)
		return 1;
	int i;
	long long res = 31;
	for (i = 2; i <= k; i++)
	{
		res= (res*31) % 1234567891;
	}
	return res%1234567891;
}
int main()
{
	long long N;
	scanf("%lld", &N);
	long long i;
	long long sum = 0;
	cin >> str;
	for (i = 0; i < N; i++)
	{
		long long num = str[i]-'a'+1;
		long long mul = POW(i);
		sum += (num * mul) % 1234567891;
	}
	printf("%lld", sum%1234567891);
}