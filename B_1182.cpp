#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int arr[21];
int chk[21];
int n,s;
int cnt = 0;
void dfs(int start, int sum)
{
	if (start == n)
    {
      	if (sum == s)
	    {
	    	cnt++;
    	}
		return;
    }
	dfs(start + 1, sum +arr[start]);
	dfs(start + 1, sum);
}
int main() {
	int i;
	scanf("%d %d", &n, &s);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
    if (s==0) cnt=-1;
	dfs(0,0);
	printf("%d\n", cnt);
}