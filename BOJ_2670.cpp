#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <map>
using namespace std;
double arr[10001];
int main()
{
	int N;
	scanf("%d", &N);
	int i;
	double res = arr[0];
	
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &arr[i]);
		
	}
	double mul = arr[0];
	for (i = 1; i < N; i++)
	{
		mul = max(arr[i], mul*arr[i]);
		res = max(mul, res);
	}
	printf("%.3lf", round(res*1000)/1000);
}