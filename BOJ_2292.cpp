#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
queue<char>q;
stack<char>s;
int res = 0;
int main()
{
	int N;
	int i = 1;
	int cnt = 1;
	scanf("%d", &N);
	while (i < N)
	{
		i += 6*cnt;
		cnt++;
	}
	printf("%d", cnt);
}