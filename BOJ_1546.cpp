#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
double res = 0;
double N;
double arr[1001];
int main()
{
	scanf("%lf", &N);
	int i;
	double MAX = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &arr[i]);
		MAX = max(MAX, arr[i]);
	}
	for (i = 0; i < N; i++)
	{
		arr[i] = (arr[i] / MAX) * 100;
		res += arr[i];
	}
	printf("%lf", res / N);

}
