#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	int A=300,B=60,C=10;
	int a,b,c;
	a=b=c=0;
	cin >> T;
	if (T>=A)
	{
	a=T/A;
	T-=A*a;
	}
	if (T>=B)
	{
	b=T/B;
	T-=B*b;
	}
	if (T>=C)
	{
	c=T/C;
	T-=C*c;
	}
	if (T==0)
	printf("%d %d %d",a,b,c);
	else
	{
		printf("-1");
	}
	
}
