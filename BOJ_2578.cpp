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
int bing[6][6];
int visited[6][6];
int binggo[12];
int call[25];
int bing_cnt=0;
ll res = 0;
int N, M;
map<int, pi> m;
void chk(int num)
{
    auto a = m[num];
    visited[a.first][a.second] = 1;

    int i, j;
    for (i = 0; i < 5; i++)
    {
        int c = 0;
        if (binggo[i])continue;
        for (j = 0; j < 5; j++)
        {
            if (!visited[i][j])
                break;
            c++;
        }
        if (c==5){
            binggo[i]=1;
            bing_cnt++;
            break;
        }
    }
    for (j = 0; j < 5; j++)
    {
        int c = 0;
        if (binggo[j+5])continue;
        for (i= 0; i < 5; i++)
        {
            if (!visited[i][j])
                break;
            c++;
        }
        if (c==5){
            binggo[j+5]=1;
            bing_cnt++;
            break;
        }
    }
    int c=0;
    for (i=0;i<5;i++)
    {
        if (binggo[10])break;
        if (!visited[i][i])break;
        c++;
        if (c==5){
            binggo[10]=1;
            bing_cnt++;
            break;
        }
    }
    c=0;
    for (i=0;i<5;i++)
    {
        if (binggo[11])break;
        if (!visited[4-i][i])break;
        c++;
        if (c==5){
            binggo[11]=1;
            bing_cnt++;
            break;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cin >> bing[i][j];
            m[bing[i][j]] = {i, j};
        }
    }
    for (i=0;i<25;i++)
        cin>>call[i];
    for (auto num:call)
    {
        res++;
        chk(num);
        if (bing_cnt>=3)break;
    }
    cout << res;
}
