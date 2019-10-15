#include <stdio.h>
long long dp[31][31];
long long peel(int h,int w)												
{
	if (h == 0 && w == 0)
		return 1;
	if (dp[h][w] != 0)
		return dp[h][w];
	if (h != 0)
		dp[h][w] += peel(h - 1, w + 1);
	if (w != 0)
		dp[h][w] += peel(h, w - 1);
	return dp[h][w];
}
int main() {
	int N;
    while(1)
    {
	scanf("%d", &N);
        if (N==0)
            break;
	printf("%lld\n", peel(N, 0));
    }
}