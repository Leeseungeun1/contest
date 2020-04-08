#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int n;
		cin >> n;
		set<int> s;
		int count = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (s.count(num)!=0) continue;
			s.insert(num);
			count++;
		}
		cout << count << "\n";
	}
}