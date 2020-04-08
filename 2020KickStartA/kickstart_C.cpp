#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
typedef long long int lli;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;
		vector<int> v;
		int before;
		cin >> before;
		for (int i = 1; i < N; i++) {
			int n;
			cin >> n;
			v.push_back(n - before);
			before = n;
		}
		sort(v.begin(), v.end());
		int size = v.size();
		int num = v[size - 1] / 2;
		int ans;
		if (v[size - 1] % 2 != 0) {
			ans = max(v[size - 2], num + 1);
		}
		else {
			ans = max(v[size - 2], num);
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}