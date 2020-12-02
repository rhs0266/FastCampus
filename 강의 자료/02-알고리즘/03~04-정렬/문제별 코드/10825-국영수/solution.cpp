#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;

#define NM 100005

int N;

struct Elem {
	string name;
	int korean, english, math;
	bool operator<(const Elem& rhs) const {
		if (korean != rhs.korean) return rhs.korean < korean;
		if (english != rhs.english) return english < rhs.english;
		if (math != rhs.math) return rhs.math < math;
		return name < rhs.name;
	}
}a[NM];


void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i].name >> a[i].korean >> a[i].english >> a[i].math;
	}
}

void pro() {
	sort(a + 1, a + 1 + N);
	for (int i = 1; i <= N; i++) {
		cout << a[i].name << '\n';
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	pro();
	return 0;
}