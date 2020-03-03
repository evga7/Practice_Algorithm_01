#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int arr[4];
int cnt = 0;
int sol(int num)
{
	int i;
	int temp = num;
	for (i = 0;i < 3; i++)
	{
		num = num % 1000 * 10 + num / 1000;
		if (temp > num) temp = num;
	}
	return temp;
}
int main()
{
	int i;
	for (i = 0; i < 4; i++)
		scanf("%d", &arr[i]);
	int res = sol(arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3]);
	for (i = 1111; i <= res; i++)
	{
		if (sol(i) == i)cnt++;
	}
	printf("%d", cnt);
}


