#include <stdio.h>
#include <map>
#include <string>
#define N 2010

using namespace std;

int a_n, a_m, b_n, b_m;
int hased_a[N];
char a[N][N], b[N][N];

int h_count, pi[N];
map<string, int> h;

int main() {
    scanf("%d %d %d %d", &a_n, &a_m, &b_n, &b_m);
    for(int i = 1; i <= a_n; i++) {
        scanf("%s", a[i] + 1);
    }
    for(int i = 1; i <= b_n; i++) scanf("%s", b[i] + 1);

    for(int i = 1; i <= a_n; i++) {
        string str = a[i] + 1;
        if (h[str] == 0) {
            h[str] = ++h_count;

            // PI 구하기
            pi[1] = 0;
            for (int j = 2; j <= a_m; j++) {
                int t = pi[j - 1];
                while (t > 0 && a[i][t + 1] != a[i][j]) t = pi[t];
                if (a[i][t + 1] == a[i][j]) t++;
                pi[j] = t;
            }

            // ~KMP~ 아호코라식으로 접근해야 할 듯
            for (int j = 1; j <= b_n; j++) {
                
            }
        }
        hased_a[i] = h[str];
    }
}
