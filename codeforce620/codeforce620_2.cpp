#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<string> arr(N);
	vector<pair<int, int>> strv;
	int index = -1;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		bool pel = true;
		for (int j = 0, k = arr[i].size() - 1; j <= k; j++, k--) {
			if (arr[i][j] != arr[i][k]) pel = false;
		}
		if (pel == true) {
			index = i;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			bool canpel = true;
			for (int f = 0, s = M - 1; f < M; f++, s--) {
				if (arr[i][f] != arr[j][s]) canpel = false;
			}
			if (canpel == true) strv.push_back({ i,j });
		}
	}
	
	int size = 0;
	if (index != -1 || !strv.empty()) {
		if (!strv.empty()) {
			size += strv.size()*M * 2;
		}
		if (index != -1) {
			size += arr[index].size();
		}
		cout << size<<"\n";
		for (int i = 0; i < strv.size(); i++) {
			cout << arr[strv[i].first];
		}
		if (index != -1) {
			cout << arr[index];
		}
		for (int i = strv.size() - 1; i >= 0; i--) {
			cout << arr[strv[i].second];
		}
	}
	else {
		cout << size;
	}
	return 0;
}