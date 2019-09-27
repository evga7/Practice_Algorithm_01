#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
queue<int>q;
int main()
{
	int N;
	scanf("%d", &N);
	int i;
	for (i = 1; i<=N; i++)
	{
		q.push(i);
	}
	while (q.size() > 1)
	{
		q.pop();
		int num = q.front();
		q.pop();
		q.push(num);
	}
	printf("%d", q.front());

}
