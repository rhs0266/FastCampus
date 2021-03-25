#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 1005

#include <map>
#include <vector>
int n, m;
map<string, int> map_name;
string names[NM];
vector<int> con[NM];
vector<string> child[NM];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> names[i];
        map_name[names[i]] = i;
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        string x, y;
        cin >> x >> y;
        con[map_name[x]].push_back(map_name[y]);
    }
}

void pro() {
    vector<string> roots;
    for (int i = 1; i <= n; i++) {
        for (int j : con[i]) {
            if (con[j].size() == con[i].size() - 1) {
                child[j].push_back(names[i]);
            }
        }
        if (con[i].size() == 0) roots.push_back(names[i]);
    }

    cout << roots.size() << "\n";
    sort(roots.begin(), roots.end());
    for (string& root : roots) cout << root << " ";
    cout << "\n";

    for (auto it = map_name.begin(); it != map_name.end(); it++) {
        int idx = it->second;
        cout << it->first << " " << child[idx].size();
        sort(child[idx].begin(), child[idx].end());
        for (string& ch : child[idx]) cout << " " << ch;
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    pro();
    return 0;
}