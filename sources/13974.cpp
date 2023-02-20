#include <stdio.h>
#define N 5001
#define INF 2000000000

int n, m, a[N];
int s[N], dp[N][N], c[N][N];

int main() {
    int t;

    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
            c[i][i] = i;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j + i <= n; j++) {
                dp[j][j + i] = INF;
                for (int tc = c[j][j + i - 1]; tc <= c[j + 1][j + i] && tc + 1 <= j + i; tc++) {
                    if (dp[j][j + i] > dp[j][tc] + dp[tc + 1][j + i] + s[j + i] - s[j - 1]) {
                        dp[j][j + i] = dp[j][tc] + dp[tc + 1][j + i] + s[j + i] - s[j - 1];
                        c[j][j + i] = tc;
                    }
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
}
