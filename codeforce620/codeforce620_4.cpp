#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int n;
		cin >> n;
		vector<char> arr(n - 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> arr[i];
		}
		vector<int> num(n);
		
		for (int i = 0; i < n; i++) {
			num[i] = n - i;
		}

		int index = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] == '>') {
				for (int j = 0; j <= (i - index) / 2; j++) {
					int temp = num[index + j];
					num[j + index] = num[i - j];
					num[i - j] = temp;
				}
				index = i + 1;
			}
		}
		for (int j = 0; j <= (n - 1 - index) / 2; j++) {
			int temp = num[index + j];
			num[j + index] = num[n - 1 - j];
			num[n - 1 - j] = temp;
		}
		for (int i = 0; i < n; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";

		for (int i = 0; i < n; i++) {
			num[i] = i + 1;
		}

		index = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] == '<') {
				for (int j = 0; j <= (i-index)/2; j++) {
					int temp = num[index + j];
					num[j+index] = num[i - j];
					num[i - j] = temp;
				}
				index = i + 1;
			}
		}
		for (int j = 0; j <= (n-1 - index) / 2; j++) {
			int temp = num[index + j];
			num[j + index] = num[n-1 - j];
			num[n-1 - j] = temp;
		}
		for (int i = 0; i < n; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}