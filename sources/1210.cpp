#include <stdio.h>
#include <algorithm>
#include <queue>
#define N 201
#define M 20001
#define INF 2000000000

using namespace std;

int n, m, s, e, a[N];
pair<int, int> p[M];
int r[N * 2][N * 2], fs[N * 2][N * 2];
bool mafia[N];

priority_queue<pair<int, int> > Q;
int d[N * 2], path[N * 2];
int pt_len, ptt[N * 2], pt[N * 2];
bool check[N * 2];

int dijkstra() {
    for (int i = 0; i <= 2 * n + 1; i++) d[i] = -INF, check[i] = false;
    d[0] = INF;
    Q.push({ d[0], 0 });

    while (!Q.empty()) {
        int x = Q.top().second; Q.pop();
        if (check[x]) continue;
        check[x] = true;

        for (int i = 1; i <= 2 * n + 1; i++) {
            if (!check[i] && d[i] < min(d[x], r[x][i])) {
                d[i] = min(d[x], r[x][i]);
                path[i] = x;
                Q.push({ d[i], i });
            }
        }
    }

    if (d[2 * n + 1] <= 0) return 0;

    int k = 2 * n + 1;
    pt_len = 0;
    while (k > 0) {
        ptt[++pt_len] = k;
        k = path[k];
    }
    ptt[++pt_len] = 0;

    for (int i = 1; i <= pt_len; i++) {
        pt[pt_len - i + 1] = ptt[i];
    }

    return d[2 * n + 1];
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &e);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d %d", &p[i].first, &p[i].second);

    for (int i = 1; i <= n; i++) {
        r[i * 2 - 1][i * 2] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        r[p[i].first * 2][p[i].second * 2 - 1] = INF;
        r[p[i].second * 2][p[i].first * 2 - 1] = INF;
    }
    r[0][s * 2 - 1] = r[e * 2][2 * n + 1] = INF;

    int flow = 0, sumFlow = 0;
    while ((flow = dijkstra()) > 0) {
        sumFlow += flow;
        for (int i = 1; i < pt_len; i++) {
            r[pt[i]][pt[i + 1]] -= flow;
            r[pt[i + 1]][pt[i]] += flow;
            fs[pt[i]][pt[i + 1]] -= flow;
            fs[pt[i + 1]][pt[i]] += flow;
        }
    }

    
}
