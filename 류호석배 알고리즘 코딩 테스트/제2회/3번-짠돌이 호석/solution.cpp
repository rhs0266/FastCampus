#include <iostream>
#include <algorithm>
#include <string>
#define NM 105
#define INF 0x7fffffff
#define vi vector<int>
FILE* in = stdin, * out = stdout;
using namespace std;

int n1, m1, n2, m2;
char a[NM][NM], b[NM][NM], temp[NM][NM];
int ans = INF;

void input() {
    cin >> n1 >> m1;
    for (int i = 1; i <= n1; i++) for (int j = 1; j <= m1; j++) cin >> a[i][j];
    cin >> n2 >> m2;
    for (int i = 1; i <= n2; i++) for (int j = 1; j <= m2; j++) cin >> b[i][j];
}
void rotate(char a[][NM], int& n, int& m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            temp[j][n - i + 1] = a[i][j];
        }
    }
    swap(n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = temp[i][j];
        }
    }
}
bool possible(int shift_row, int shift_col) {
    for (int ai = 1; ai <= n1; ai++) {
        for (int aj = 1; aj <= m1; aj++) {
            if (a[ai][aj] == '0')
                continue;
            int bi = ai + shift_row, bj = aj + shift_col;
            if (1 <= bi && bi <= n2 && 1 <= bj && bj <= m2 && b[bi][bj] == '1')
                return false;
        }
    }
    return true;
}
void pro() {
    for (int rot = 1; rot <= 4; rot++) {
        rotate(a, n1, m1);
        for (int shift_row = -51; shift_row <= 51; shift_row++) {
            for (int shift_col = -51; shift_col <= 51; shift_col++) {
                if (possible(shift_row, shift_col)) {
                    int row = max(n2 - 1, shift_row + n1 - 1) - min(0, shift_row) + 1;
                    int col = max(m2 - 1, shift_col + m1 - 1) - min(0, shift_col) + 1;
                    ans = min(ans, row * col);
                }
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    pro();
    return 0;
}

