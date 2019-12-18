#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int arr[1000001];
int main()
{
    int N;
    scanf("%d",&N);
    int i;
    for (i=0;i<N;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+N);
    printf("%d %d",arr[0],arr[N-1]);
}