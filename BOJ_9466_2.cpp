#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res = 0;
int T;
int arr[100001];
int visited[100001];
int chk[100001];
bool is_inside(int x, int y)
{
    if (x >= N || x < 0 || y < 0 || y >= M)return false;
    return true;
}

void solve(int start)
{
    int next = arr[start];
    visited[start] = 1;
    if (!visited[next])solve(next);
    else if (!chk[next])
    {
        int i;
        for (i = next;i!=start;i=arr[i])
                res++;
        res++;
    }
    chk[start] = 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    cin >> T;
    while (T--)
    {
        cin >> N;
        res = 0;
        for (i = 1; i <= N; i++)
        {
            cin >> arr[i];
        }
        memset(chk, 0, sizeof(chk));
        memset(visited, 0, sizeof(visited));
        for (i = 1; i <= N; i++)
        {
            if (!chk[i])
                solve(i);
        }
        cout << N - res << "\n";
    }

}