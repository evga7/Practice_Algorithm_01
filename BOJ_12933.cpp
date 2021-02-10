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
string str;
int visited[2501];
int ori[5]={'q','u','a','c','k'};
vector<int> v;
void solve(int idx, int cnt, int check)
{
    if (idx >= str.size())
        return;
        char cur=ori[cnt];
    if (str[idx]==cur&&!visited[idx])
    {
        v.push_back(idx);
        if (cur=='k'&&!check)
        {
            check=1;
            res++;
        }
        if (cnt==4)
            cnt=0;
        else
            cnt++;
        visited[v.back()]=1;
        v.pop_back();
    }
    solve(idx+1,cnt,check);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    int i, j;
    int flag=0;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == 'q' && !visited[i])
        {
            solve(i,0,0);
        }
    }
    for (i=0;i<str.size();i++)
    if (!visited[i])flag=1;
    if (!res||str.size()%5)
    flag=1;
    if (flag)
    cout<<"-1";
    else
    cout<<res;
}
