#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int N;
	int i = 1;
	int sum = 0;
	scanf("%d", &N);
	while (i + sum < N)
	{
		sum += i++;
	}
	int a,b;
	if (i % 2==0)
		a = N- sum;
	else 
		a=i + 1 - (N - sum);
	b = i+1 - a;
	printf("%d/%d", a, b);
}