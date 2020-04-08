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
		int N, K, P;
		cin >> N >> K >> P;
		vector<vector<int>> arr(51, vector<int>(2000));
		for (int j = 1; j <= K; j++) {
			int num;
			cin >> num;
			arr[0][j] = arr[0][j - 1] + num;
		}
		int maximum = arr[0][P];
		for (int i = 1; i < N; i++) {
			int sum = 0;
			for (int j = 1; j <= K; j++) {
				int num;
				cin >> num;
				sum = sum + num;
				for (int k = P - j; k >= 0; k--) {
					arr[i][j + k] = max(arr[i][j+k],max(arr[i - 1][j + k], sum + arr[i - 1][k]));
					if (j + k == P) maximum = max(maximum, arr[i][j + k]);
				}
			}
		}
		
		cout << "Case #" << tc << ": " << maximum << "\n";
	}
}