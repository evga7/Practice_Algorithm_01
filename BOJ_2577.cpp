#include <stdio.h>
void num()
{
	int A, B, C;
	int cnt[10] = { 0 };
	int sum;
	char temp[100];
	int i;
	scanf("%d %d %d", &A, &B, &C);
	sum = A * B*C;
	sprintf(temp, "%d",sum);
	for (i = 0;i < strlen(temp);i++)
		cnt[temp[i]-'0']++;
	for (i=0;i<10;i++)
		printf("%d\n",cnt[i]);
}
int main()
{
	num();
}