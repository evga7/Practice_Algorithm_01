#include <string> 
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 987654321
using namespace std;
int N,M;
priority_queue<int,vector<int>,greater<int>>pq;
int res;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	int num;
	int i;
	for (i = 0; i <N * N; i++)
	{
		cin >> num;
		pq.push(num);
		if (pq.size() > N)
			pq.pop();
		
	}
	cout << pq.top();

}