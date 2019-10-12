#include <stdio.h>
#include <string.h>
char stack[100000];
int top;
void push(char data)
{
	stack[top++] = data;
}
void pop()
{
	top--;
}
int stack_size()
{
	return top;
}
int main() {

	char arr[100000];
	int i;
	int cnt = 0;
	top = 0;
	scanf("%s", arr);
	for (i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == '(')
		{
			push('(');
		}
		else if (arr[i]==')')
		{
			if (arr[i - 1] == '(')
			{
				pop();
				cnt += stack_size();
			}
			else
			{
				pop();
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}