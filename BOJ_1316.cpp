#include <cstring> 
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#define MAX 987654321
using namespace std;
int N;
string S;
int res = 0;
int arr[200];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int i,j;
	cin >> N;
	
	for (i = 0; i < N; i++)
	{
		cin >> S;
		memset(arr, 0, sizeof(arr));
		int flag = 0;
		int size = S.size();
		arr[S[0]] = 1;
		for (j = 1; j < size; j++)
		{
			if (arr[S[j]])
			{
				if (S[j - 1] != S[j])
				{
					flag = 1;
					break;
				}
			}
			else
			{
				arr[S[j]] = 1;
			}
		}
		if (!flag)
			res++;
	}
	cout << res;

}