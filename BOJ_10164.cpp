#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int N,M,K;
int arr[21][21];
int X,Y;
int res=0;
void DFS(int x,int y,int cnt,int flag)
{
	if (x>=N||y>=M)
	return;
	if (x==N-1&&y==M-1&&flag)
	res++;
	if (x==X&&y==Y)
		flag=1;
	DFS(x+1,y,cnt+1,flag);
	DFS(x,y+1,cnt+1,flag);
	return;
}
int main()
{
	int i,j;
	cin >> N>>M>>K;
	int num=0;
	int flag=0;
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
		{
		arr[i][j]=++num;
		if (num==K)
		{
			X=i,Y=j;
			flag=1;
			break;
		}
		}
		if (flag)
		break;
	}
	DFS(0,0,0,0);
	printf("%d",res);
}
