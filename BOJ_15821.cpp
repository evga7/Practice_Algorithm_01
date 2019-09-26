#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
vector<double>v;
int main() {
	int N, M,K;
	scanf("%d %d", &N,&K);
	int i,j;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &M);
		double Max = 0;
		for (j = 0; j < M; j++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			double dis = sqrt(pow(x, 2) + pow(y, 2));
			Max = max(dis, Max);
		}
		v.push_back(Max);
	}
	sort(v.begin(), v.end());
	printf("%.2lf", pow(v[K-1], 2));
}