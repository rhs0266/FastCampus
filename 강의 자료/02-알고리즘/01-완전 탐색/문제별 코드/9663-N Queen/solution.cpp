#include <iostream>
typedef long long int ll;
using namespace std;

int N, col[15], ans;
void input() {
	cin >> N;
}

bool attackable(int r1, int c1, int r2, int c2) {
	if (c1 == c2) return true;
	if (r1 - c1 == r2 - c2) return true;
	if (r1 + c1 == r2 + c2) return true;
	return false;
}

void rec_func(int row) {
    if (row == N + 1) {
        ans++;
    }
    else {
        for (int c = 1; c <= N; c++) {
            bool possible = true;
            // valid check (row, c)
            for (int i = 1; i <= row - 1; i++) {
                // (i, col[i])
                if (attackable(row, c, i, col[i])) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                col[row] = c;
                rec_func(row + 1);
                col[row] = 0;
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	rec_func(1);
    cout << ans;
	return 0;
}