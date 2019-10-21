#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
map<string, int> set1;
map<int, string>set2;
void pokemon()
{
	int N, M;
	int i,j;
	int num;
	scanf("%d %d", &N,&M);
	char poke_name[21];
	char op[21];
	for (i = 0; i < N; i++)
	{
		scanf("%s", poke_name);
		set1[poke_name] = i;
		set2[i] = poke_name;
	}
	for (i = 0; i < M; i++)
	{
		scanf("%s", op);
		if (op[0] >= '0'&&op[0] <= '9')
		{
			printf("%s\n", set2[atoi(op)-1].c_str());
		}
		else
			printf("%d\n", set1[op]+1);
	}
}
int main()
{
	pokemon();
}