#include <stdio.h>
#define N 100001

int n, nn, m;
long long tree[N * 4];

void tree_push(int lev, int l, int r, int x, int y, long long num) {
    int mid = (l + r) / 2;
    if (x <= l && r <= y) {
        tree[lev] += num;
        return;
    }
    if (r < x || y < l) return;
    tree_push(lev * 2, l, mid, x, y, num);
    tree_push(lev * 2 + 1, mid + 1, r, x, y, num);
}

long long tree_get(int lev) {
    if (lev == 0) return 0;
    return tree[lev] + tree_get(lev / 2);
}

int main() {
    scanf("%d", &n);
    for (nn = 1; nn < n; nn *= 2);
    for (int i = 1; i <= n; i++) scanf("%lld", &tree[nn + i - 1]);
    scanf("%d", &m);
    while (m--) {
        int k, x, y, z;
        scanf("%d %d", &k, &x);
        if (k == 1) {
            scanf("%d %d", &y, &z);
            tree_push(1, 1, nn, x, y, z);
        }
        else {
            printf("%lld\n", tree_get(nn + x - 1));
        }
    }
}
