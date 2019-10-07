#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int num;
		scanf("%d", &num);
		int i = 0;
		while (1)
		{
			if ((i + 1)*(1 + (i + 1)) <= num)
			{
				i++;
			}
			else
				break;
		}
		printf("%d\n", i);
	}
}
