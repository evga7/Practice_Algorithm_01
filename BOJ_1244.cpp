#include <bits/stdc++.h>
#include <unordered_map>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>> pi2;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
ll res = 0;
int N, M;
int arr[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    cin >> N;
    for (i = 1; i <=N; i++)
    {
        int num;
        cin >> num;
        arr[i]=num;
    }
    cin>>M;
    int a,b;
    for (i=1;i<=M;i++)
    {
        cin>>a>>b;
        if (a==1)
        {
            for (j=b;j<=N;j+=b)
            {
                arr[j]=1-arr[j];
            }
        }
        else
        {
            arr[b]=1-arr[b];
            int left=b-1;
            int right=b+1;
            while (left>0&&right<=N&&arr[left]==arr[right])
            {
                arr[left]=1-arr[left];
                arr[right]=1-arr[right];
                left--;
                right++;
            }
        }
    }
    for (i=1;i<=N;i++)
    {
        cout<<arr[i]<< " ";
        if (i%21==0) cout<<"\n";
    }
    
}
