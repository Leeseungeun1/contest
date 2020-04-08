#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool checkcol[101][101];
bool checkrow[101][101];
int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		int trace = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int num;
				cin >> num;
				if (i == j)trace += num;
				checkrow[i][num] = true;
				checkcol[j][num] = true;
			}
		}
		int row = 0, col = 0;
		for (int i = 1; i <= N; i++) {
			int num = 0;
			for (int j = 1; j <= N; j++) {
				if (checkrow[i][j] == true) num++;
			}
			if (num != N) row++;
		}
		for (int j = 1; j <= N; j++) {
			int num = 0;
			for (int i = 1; i <= N; i++) {
				if (checkcol[j][i] == true) num++;
			}
			if (num != N) col++;
		}
		cout << "Case #" << tc << ": " << trace << " " << row << " " << col << "\n";
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				checkrow[i][j] = checkcol[i][j] = false;
			}
		}
	}
	return 0;
}