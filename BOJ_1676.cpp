#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N;
	int res=0;
	scanf("%d", &N);
	int i;
	for (i = 2; i <= N; i++)
	{
		if (i%5==0) res++;
        if (i%25==0)res++;
        if (i%125==0)res++;
	}
    printf("%d",res);
}
