#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 55

int N, M, visit[NM][NM], dist_water[NM][NM], dist_hedgehog[NM][NM];
char a[NM][NM];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
}

#include <queue>
// 모든 물들을 시작으로 동시에 BFS 시작!
void bfs_water() {
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist_water[i][j] = -1;
            visit[i][j] = false;
            if (a[i][j] == '*') {
                Q.push(i);
                Q.push(j);
                dist_water[i][j] = 0;
                visit[i][j] = true;
            }
        }
    }
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        int y = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;  // 지도를 벗어나는 곳으로 가는가?
            if (a[nx][ny] != '.') continue;  // 갈 수 있는 칸인지 확인해야 한다.
            if (visit[nx][ny]) continue;  // 이미 방문한 적이 있는 곳인가?
            Q.push(nx);
            Q.push(ny);
            visit[nx][ny] = true;
            dist_water[nx][ny] = dist_water[x][y] + 1;
        }
    }
}

// 고슴도치를 시작으로 동시에 BFS 시작!
static void bfs_hedgehog() {
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist_hedgehog[i][j] = -1;
            visit[i][j] = false;
            if (a[i][j] == 'S') {
                Q.push(i);
                Q.push(j);
                dist_hedgehog[i][j] = 0;
                visit[i][j] = true;
            }
        }
    }
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        int y = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;  // 지도를 벗어나는 곳으로 가는가?
            if (a[nx][ny] != '.' && a[nx][ny] != 'D') continue;  // 갈 수 있는 칸인지 확인해야 한다.
            if (dist_water[nx][ny] != -1 && dist_water[nx][ny] <= dist_hedgehog[x][y] + 1) continue;  // 물에 잠기지는 않는가?
            if (visit[nx][ny]) continue;  // 이미 방문한 적이 있는 곳인가?
            Q.push(nx);
            Q.push(ny);
            visit[nx][ny] = true;
            dist_hedgehog[nx][ny] = dist_hedgehog[x][y] + 1;
        }
    }
}

void pro() {
    bfs_water();
    bfs_hedgehog();
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (a[i][j] == 'D'){
                if (dist_hedgehog[i][j] == -1) cout << "KAKTUS";
                else cout << dist_hedgehog[i][j];
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    pro();
    return 0;
}