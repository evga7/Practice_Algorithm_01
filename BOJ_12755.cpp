#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string str = "";
	int num = 0;
	int N;
	int res = 1;
	scanf("%d", &N);
	int cnt = 0;
	while (1)
	{

		num++;
		int temp = num;
		cnt = 0;
		while (temp != 0)
		{
			cnt++;
			temp /= 10;
		}
		if (res+cnt > N)
		{
			str = to_string(num);
			printf("%c", str[N-res]);
			break;
		}
		res += cnt;
	}
}