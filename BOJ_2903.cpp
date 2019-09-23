#include <iostream>

int main()
{
    int cnt=2;
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
        cnt+=cnt-1;
    printf("%d",cnt*cnt);
}