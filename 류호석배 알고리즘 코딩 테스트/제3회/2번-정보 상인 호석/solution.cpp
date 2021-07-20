#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
#define NM 100005
#define INF 0x7fffffff

#include <unordered_map>
#include <string>
unordered_map<string, int> name_map;
int Q, pid_cnt;
priority_queue<int> info[NM];

void input(){
    cin >> Q;
}

int get_pid(string name) {
    if (!name_map.count(name)) name_map[name] = ++pid_cnt;
    return name_map[name];
}

void pro() {
    long long int ans = 0;
    while (Q--) {
        int query;
        cin >> query;
        string name;
        cin >> name;
        int pid = get_pid(name);
        if (query == 1) {
            int k;
            cin >> k;
            while (k--) {
                int x;
                cin >> x;
                info[pid].push(x);
            }
        } else {
            int b;
            cin >> b;
            while (b-- && !info[pid].empty()) {
                ans += info[pid].top();
                info[pid].pop();
            }
        }
    }
    cout << ans;
}

int main() {
    input();
    pro();
    return 0;
}