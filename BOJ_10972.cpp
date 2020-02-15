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
	int i;
	scanf("%d", &N);
	int num;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		v.push_back(num);

	}
	if (next_permutation(v.begin(), v.end()))
		for (i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
	else
		printf("-1");
	
	
}
