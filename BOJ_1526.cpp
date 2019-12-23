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
int N;
int res = 0;
void DFS(int sum)
{
	if (sum > N)
		return;
	DFS(sum * 10 + 7);
	DFS(sum * 10 + 4);
	res = max(res, sum);
		
}
int main()
{
	cin >> N;
	DFS(0);
	cout << res;
}