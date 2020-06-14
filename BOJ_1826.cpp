#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> pq;
int n, l, p, it, r;
pair<int, int> a[10002];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    scanf("%d%d", &l, &p);
    sort(a, a + n);
    while (p < l) {
        while (a[it].first <= p) {
            if (it == n)break;
            pq.push(a[it].second);
            it++;
        }
        if (!pq.size())break;
        r++;
        p += pq.top();
        pq.pop();
    }
    printf("%d\n", p < l ? -1 : r);
    return 0;
}
