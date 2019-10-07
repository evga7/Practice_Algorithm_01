#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;
int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main()
{
	int N;
	int year = 2014;
	int month = 4;
	int day = 1;
	scanf("%d", &N);
	while (1)
	{
		if (N == 0)
			break;
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			days[2] = 29;
		}
		else
			days[2] = 28;

		if (N >=days[month])
		{
			N -= days[month];
			day += days[month];
			if (day > days[month])
			{
				day %= days[month];
				month = (month % 12) + 1;
                if (month == 1)
				year++;
			}

		}
		else
		{
			day += N;
			if (day > days[month])
			{
				day %= days[month];
				month = (month % 12) + 1;
                			if (month == 1)
				year++;
			}

			break;
		}
	}
	printf("%d-", year);
	if (month < 10)
		printf("0%d-", month);
	else
		printf("%d-", month);
	if (day <10)
		printf("0%d", day);
	else
		printf("%d", day);

}
