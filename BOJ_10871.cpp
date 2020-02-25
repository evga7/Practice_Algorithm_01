#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;

vector<int> v;
int main()
{
	int N;
	int X;
	scanf("%d %d", &N, &X);
	int i;
	int num;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if (num < X)
			v.push_back(num);
	}
	for (i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	
}
