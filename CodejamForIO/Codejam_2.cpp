#include <iostream>
#include <algorithm>

using namespace std;
//pair<int, char> arr[2000];
char arr[2000];
int numbers[2000];
int bruteforce(int num, int N, int left, int right) {
	if (num >= N) {
		for (int i = 0; i < N; i++) {
			if (arr[numbers[i]-1] == 'L') left = left - 1;
			else right = right - 1;
			if (abs(left - right) > 1) return -1;
		}
		return 1;
	}
	else {
		if (N - num == 1) {
			arr[num] = 'L';
			if (bruteforce(num + 1, N, left + 1, right) == 1) return 1;
			arr[num] = 'R';
			if (bruteforce(num + 1, N, left, right + 1) == 1) return 1;
		}
		else {
			arr[num] = 'L';
			arr[num + 1] = 'R';
			if (bruteforce(num + 2, N, left + 1, right + 1) == 1) return 1;
			arr[num] = 'R';
			arr[num + 1] = 'L';
			if (bruteforce(num + 2, N, left + 1, right + 1) == 1) return 1;
		}
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> numbers[i];
		}
		if (bruteforce(0, N, 0, 0) == 1) {
			cout << "Case #" << tc << ": ";
			for (int i = 0; i < N; i++) {
				cout << arr[i];
			}
			cout << "\n";
		}
	}
	return 0;
}