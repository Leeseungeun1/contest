#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int start, end, tall, small;
		cin >> start >> end >> tall >> small;
		int distance = end - start;
		int sum = tall + small;
		if (distance%sum != 0) {
			cout << "-1\n";
		}
		else {
			cout << distance / sum << "\n";
		}
	}
	return 0;
}