int main()
{

	int i;
	int N;
	long long int dp[101]={0,1,1,1,2,2,3,4,5,7,9};
	scanf("%d", &N);
	for (i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	int num;
	while (N--)
	{
		scanf("%d", &num);
		printf("%lld\n", dp[num]);
	}
}