#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int arr[10001];
int main()
{
int N;
scanf("%d",&N);
int i;
for (i=0;i<N;i++)
scanf("%d",&arr[i]);
sort(arr,arr+N);
printf("%d",arr[N-1]-arr[0]);
}
