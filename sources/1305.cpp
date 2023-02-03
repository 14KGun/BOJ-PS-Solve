#include <stdio.h>
#define N 1000010

int n, pi[N];
char a[N];

int main() {
    scanf("%d %s", &n, a + 1);
    for (int i = 2; i <= n; i++) {
        int t = pi[i - 1];
        while (t > 0 && a[t + 1] != a[i]) t = pi[t];
        if (a[t + 1] == a[i]) pi[i] = ++t;
    }
    printf("%d", n - pi[n]);
}
