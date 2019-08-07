#include <stdio.h>
int main() {
	int E, S, M;
	int A, B, C;
	scanf("%d %d %d", &E, &S, &M);
	A = B = C = 1;
	int cnt = 1;
	while (1)
	{
		if (A == E && B == S && C == M)
		{
			printf("%d", cnt);
			break;
		}
		A %= 15;
		B %= 28;
		C %= 19;
		A++, B++, C++;
		cnt++;
	}
}