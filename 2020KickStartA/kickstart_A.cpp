#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
typedef long long int lli;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, B;
		cin >> N >> B;
		vector<int> money(B+1);
		vector<int> house(N);
		for (int i = 0; i < N; i++) {
			cin >> house[i];
		}
		sort(house.begin(), house.end());
		int num = 0, sum = 0;
		for (int i = 0; i < N; i++) {
			sum = sum + house[i];
			if (sum <= B) num++;
		}
		
		cout << "Case #" << tc << ": " << num << "\n";
	}
	return 0;
}