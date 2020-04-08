#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		vector < pair<pair<int, int>, int>> v(N);
		vector<char> ans(N);
		int c=-1, j=-1;
		for (int i = 0; i < N; i++) {
			int s, e;
			cin >> s >> e;
			v[i] = { {s,e},i };
		}
		sort(v.begin(), v.end());
		bool possible = true;
		for (int i = 0; i < N; i++) {
			if (c == -1) {
				ans[v[i].second] = 'C';
				c = i;
			}
			else if (j == -1) {
				ans[v[i].second] = 'J';
				j = i;
			}
			else {
				if (v[i].first.first >= v[c].first.second) {
					ans[v[i].second] = 'C';
					c = i;
				}
				else if (v[i].first.first >= v[j].first.second) {
					ans[v[i].second] = 'J';
					j = i;
				}
				else {
					possible = false;
					break;
				}
			}
		}
		if (possible == false) {
			cout << "Case #" << tc << ": IMPOSSIBLE\n";
		}
		else {
			cout << "Case #" << tc << ": ";
			for (int i = 0; i < N; i++) {
				cout << ans[i];
			}
			cout << "\n";
		}
	}
	return 0;
}