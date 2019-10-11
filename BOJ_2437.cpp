#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#include <queue>
using namespace std;
int arr[100001];
int main()
{
	int N;
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	int sum = arr[0];
    if (sum>1)
    {
        cout<<1;
        return 0;
    }
	for (i = 1; i < N; i++)
	{
		if (sum+1<arr[i])
		{
			break;
		}
		sum+=arr[i];
	}
	cout << sum+1;
}