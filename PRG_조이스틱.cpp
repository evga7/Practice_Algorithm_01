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
int cnt[21];
int chk_min(char C)
{
    int num = 0;
    int a = C - 'A';
    int b = 'A' + 26 - C;
    return min(a, b);
}
int solution(string name)
{
    int s = name.size();
    int answer = 0;
    string str;
    int i;
    for (i = 0; i < s; i++)
    {
        str = str + 'A';
    }
    for (i = 0; i < s; i++)
    {
        cnt[i] = chk_min(name[i]);
    }
    int idx = 0;

    while (1)
    {
        if (cnt[idx])
        {
            answer += cnt[idx];
            cnt[idx] = 0;
        }
        int b = 0;
        for (i = 0; i < s; i++)
            if (cnt[i])
                b++;
        if (!b)
            break;

        int left = idx - 1;
        int right = idx + 1;
                    if (left < 0)
                left = s - 1;
                            if (right >= s)
                right = 0;
        int l_cnt = 0;
        int r_cnt = 0;
        while (1)
        {
            r_cnt++;
            if (cnt[right])
                break;
            right++;
            if (right >= s)
                right = 0;
        }
        while (1)
        {
            l_cnt++;
            if (cnt[left])
                break;
            left--;
            if (left < 0)
                left = s - 1;
        }
        if (r_cnt <= l_cnt)
        {
            idx = right;
            answer += r_cnt;
        }
        else
        {
            answer += l_cnt;
            idx = left;
        }
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << solution("JAN");
}
