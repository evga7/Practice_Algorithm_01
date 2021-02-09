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
ll arr[100001];
vector<int>v;
int main()

{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int num;
    int i,j;
    for (i=0;i<N;i++)
    {
        cin>>num;
        v.push_back(num);
    }
    for (i=1;i<N;i++)
        arr[i]+=arr[i-1]+v[i];
    for (i=0;i<N-1;i++)
    res+=(arr[N-1]-arr[i])*v[i];
        cout<<res;
}
