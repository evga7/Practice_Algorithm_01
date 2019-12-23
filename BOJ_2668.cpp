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
int arr[101];
vector <int> visited(101, 0);
vector<int> v;
void DFS(int Start, int Next)
{
	if (visited[Next])
	{
		if (Start == Next)
			v.push_back(Start);
	}
	else 
	{
		visited[Next]++;	
		DFS(Start, arr[Next]);
	}
}
int main()
{
	int N;
	cin >> N;
	int i;
	int num;
	for (i = 1; i <=N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	for (i = 1; i <= N; i++)
	{
		fill(visited.begin(), visited.end(), 0);
		DFS(i, i);
	}
	cout << v.size()<<endl;
	for (auto a : v)
		cout << a << endl;

}