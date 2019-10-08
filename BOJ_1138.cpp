#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;
list<int>L;
list<int>::iterator it;
int arr[11];
int main()
{

	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (i = N-1; i>=0; i--)
	{
		it = L.begin();
		for (j=0;j<arr[i];j++)
			*it++;
		L.insert(it, i+1);
	}
	int pos = 0;
	for (it = L.begin(); it != L.end(); it++)
		cout << *it << " ";
}