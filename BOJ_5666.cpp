#include <stdio.h>
void hotdog()
{
	double H, P;
	while (~scanf("%lf %lf", &H, &P))
	{
		printf("%.2f\n", H / P);
	}
}
int main()
{
	hotdog();
}