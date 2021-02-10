#include <bits/stdc++.h>
#include <unordered_map>
#define MAX 987654321
#define MIN -987654321
using namespace std;

typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>> pi2;
int dx[4] = {-2, -1, 1, 2};
int dy[4] = {1, 2, 2, 1};
ll res = 0;
int N, M;
int arr[101];
int main()

{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int i;
    int a,b;
    memset(arr,-1,sizeof(arr));
    for (i=0;i<N;i++)
    {
        cin>>a>>b;
        if (arr[a]!=-1&&arr[a]!=b)
            res++;
        arr[a]=b;
    }
    cout<<res;
}
