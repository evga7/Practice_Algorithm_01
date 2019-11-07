#include <stdio.h>
void num_of_a()
{
	char arr[101];
	int i;
	int cnt[26] = { 0 };
	scanf("%s", arr);
	for (i = 0;i < strlen(arr);i++)
	{
		cnt[arr[i] - 'a']++;
	}
	for (i=0;i<26;i++)
	printf("%d ", cnt[i]);
}
int main()
{
	num_of_a();
}