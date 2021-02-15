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
int N, M;
int res = 0;
int train[100001];
set<int>s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int i, j;
    for (i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c;
            train[b]= train[b]|(1<<c);
        }
        else if (a == 2)
        {
            cin >> b >> c;
            train[b]=train[b]&~(1<<c);
        }
        else if (a == 3)
        {
            cin >> b;
            train[b]=train[b]<<1;
            train[b]=train[b]&((1<<21)-1);
        }
        else if (a == 4)
        {
            cin >> b;
            train[b]=train[b]>>1;
            train[b]=train[b]&~1;
        }
    }
    for (i=1;i<=N;i++)
    {
        if (s.find(train[i])==s.end())
        {
            s.insert(train[i]);
            res++;
        }
    }
    cout<<res;
}
