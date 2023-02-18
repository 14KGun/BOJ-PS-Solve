#include <stdio.h>
#include <vector>
#define N 100001

using namespace std;
int n, m, nn, tree[N * 4];
int i2n[N], i2e[N], cnt_i2n;
vector<int> r[N];

int buildTree(int lev) {
    i2n[lev] = i2e[lev] = ++cnt_i2n;
    for (auto i : r[lev]) i2e[lev] = buildTree(i);
    return i2e[lev];
}

void pushTree(int lev, int l, int r, int x, int y, int num) {
    int mid = (l + r) / 2;
    if (x <= l && r <= y) {
        tree[lev] += num;
        return;
    }
    if (r < x || y < l) return;
    pushTree(lev * 2, l, mid, x, y, num);
    pushTree(lev * 2 + 1, mid + 1, r, x, y, num);
}

int getTree(int lev) {
    if (lev == 1) return tree[lev];
    return tree[lev] + getTree(lev / 2);
}

int main() {
    int x, y, z;

    scanf("%d %d", &n, &m);
    for (nn = 1; nn < n; nn *= 2);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x > 0) r[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (i2n[i] == 0) buildTree(i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        if (x == 1) {
            scanf("%d", &z);
            pushTree(1, 1, nn, i2n[y], i2e[y], z);
        } else {
            printf("%d\n", getTree(nn + i2n[y] - 1));
        }
    }
}
