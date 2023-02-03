#include <stdio.h>
#include <string.h>
#define N 1000010

int len_a, len_b, pi[N];
char a[N], b[N];

int result_len;
int result[N];

int main() {
    fgets(a + 1, N, stdin);
    fgets(b + 1, N, stdin);
    len_a = strlen(a + 1) - 1;
    len_b = strlen(b + 1) - 1;

    // PI 구하기
    for (int i = 2; i <= len_b; i++) {
        int t = pi[i - 1];
        while (t > 0 && b[t + 1] != b[i]) t = pi[t];
        if (b[t + 1] == b[i]) pi[i] = t + 1;
    }

    // KMP
    int prefix_len = 0;
    for (int i = 1; i <= len_a; i++) {
        while (prefix_len > 0 && a[i] != b[prefix_len + 1]) {
            prefix_len = pi[prefix_len];
        }
        if (a[i] == b[prefix_len + 1]) prefix_len++;
        if (prefix_len == len_b) {
            result[++result_len] = i - len_b + 1;
            prefix_len = pi[prefix_len];
        }
    }

    // Output
    printf("%d\n", result_len);
    for (int i = 1; i <= result_len; i++) printf("%d ", result[i]);
}
