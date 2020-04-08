#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <string>
using namespace std;

char str[101];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	char buffer;
	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;
		int num = -1;
		queue<char> q;
		for(int i=0;i<s.size();i++){
			int cnum = s[i] - '0';
			if (num != -1) {
				if (cnum < num) {
					int n = num - cnum;
					for (int i = 0; i < n; i++) {
						q.push(')');
					}
				}
				if (cnum > num) {
					int n = cnum - num;
					for (int i = 0; i < n; i++) {
						q.push('(');
					}
				}
			}
			else {
				for (int i = 0; i < cnum; i++) {
					q.push('(');
				}
			}
			q.push(s[i]);
			num = cnum;
		}
		for (int i = 0; i < num; i++) {
			q.push(')');
		}
		cout << "Case #" << tc << ": ";
		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
		cout << "\n";
	}
	return 0;
}