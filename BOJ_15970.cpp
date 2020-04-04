#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int N;
vector<int> v[5001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >>N;
	int i,j;
	int maxNum=0;
	for (i=0;i<N;i++)
	{
		int a,b;
		cin>>a>>b;	
		v[b].push_back(a);
		maxNum=max(maxNum,b);
	}
	
	long long sum=0;
	for (i=0;i<=maxNum;i++)
	{
		if (v[i].empty())
		continue;
		sort(v[i].begin(),v[i].end());
		sum+=v[i][1]-v[i][0];
		for (j=1;j<v[i].size()-1;j++)
		{
			int num=v[i][j];
			sum+=min(num-v[i][j-1],v[i][j+1]-num);
		}
		sum+=v[i][v[i].size()-1]-v[i][v[i].size()-2];
	}
	cout<< sum;
}

