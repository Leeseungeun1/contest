#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

queue<char> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string c;
		int num = 0;
		int numI = 0;
		int numi = 0;
		cin >> c;
		for (int i = 0; i < c.size(); i++) {
			if (c[i] == 'i') numi++;
			else if (c[i] == 'I') numI++;
			else if(c[i]=='O'){
				if (numI > 0) {
					num++;
					numI--;
				}
				else {
					numi--;
				}
			}
			else {
				if (numi > 0) {
					numi--;
				}
				else {
					numI--;
				}
			}
		}
		cout << "Case #" << tc << ": " << num << "\n";
	}
	return 0;
}