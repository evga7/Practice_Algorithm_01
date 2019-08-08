#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
char arr[16];
int l, c;
void dfs(int start, int mo, int ja, int cnt,string s)
{
	if (cnt == l)
	{
		if (mo >= 1 && ja >= 2)
			cout << s << endl;
		return;
	}
	if (start == c)
		return;
	if (arr[start] == 'a' || arr[start] == 'e' || arr[start] == 'i'||arr[start] == 'o'||arr[start] == 'u')
		dfs(start + 1, mo + 1, ja, cnt + 1, s + arr[start]);
	else
		dfs(start + 1, mo, ja+1, cnt + 1, s + arr[start]);
	dfs(start + 1, mo, ja, cnt, s);
}
int main() {
	int i;
	scanf("%d %d", &l, &c);
	getchar();
	for (i = 0; i < c; i++)
		scanf("%2c", &arr[i]);
	sort(arr, arr + c);
	dfs(0,0,0,0,"");
}