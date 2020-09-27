#include <string> 
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 987654321
using namespace std;
int N,M;
int arr[101][101];
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N>>M;
	int i, j, k;
	int a, b;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
	}
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{

				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
			}
		}
	}

	for (i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (j = 1; j <= N; j++)
		{
			//a>b이면서 b>a가 아니면 
			if (!arr[i][j] &&!arr[j][i])cnt++;
		}
		cout << cnt-1 << "\n";
	}
}