#include <stdio.h>
void doubles()
{
	int arr[201] = { 0 };
	int arr2[201] = { 0 };
	int N;
	int cnt = 0;
	int i;
	int cnt2 = 0;
	//N을 입력받고 arr[N]번째를 숫자 1로 입력시켜서
	//N번째가 들어왔다는것을 입력받고 arr2에 그 값들을 넣음
	//그래서 arr의 배열의 arr2[]의 *2 값이 1이면 더블인값이있는것이므로 cnt증가
	while (1) 
	{
		scanf("%d", &N);
		if (N == -1)
			break;
		if (N == 0)
		{
			for (i = 0;i < cnt;i++)
			{
				if (arr[arr2[i]*2]==1) 
					cnt2++;
			}
			printf("%d\n", cnt2);
			for (i = 0;i < cnt;i++) //arr 함수들 초기화
			{
				arr[arr2[i]] = 0;
				arr2[i] = 0;
			}
			cnt = cnt2 = 0;
		}
		else
		{
			arr2[cnt++] = N;
			arr[N] = 1;
		}

	}
}
int main()
{
	doubles();
}
