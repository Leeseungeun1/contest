#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int x;
		cin >> x;
		cout << "1 " << x - 1 << "\n";
	}
	return 0;
}