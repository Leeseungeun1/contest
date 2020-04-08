#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
queue<char> IO;
queue<char> Io;
queue<char> iO;
queue<char> io;
int maxnum = 0;
void bruteforce(string s, int n, int num) {
	if (n >= s.size()) {
		maxnum = max(num, maxnum);
	}
	else {
		if(s[n]=='I'){
			if (IO.empty()) {
				IO.push(s[n]);
				bruteforce(s, n + 1, num);
				IO.pop();
			}
			if (Io.empty()) {
				Io.push(s[n]);
				bruteforce(s, n + 1, num);
				Io.pop();
			}
		}
		else if (s[n] == 'i') {
			if (iO.empty()) {
				iO.push(s[n]);
				bruteforce(s, n + 1, num);
				iO.pop();
			}
			if (io.empty()) {
				io.push(s[n]);
				bruteforce(s, n + 1, num);
				io.pop();
			}
		}
		else if (s[n] == 'O') {
			if (!IO.empty()) {
				IO.pop();
				bruteforce(s, n + 1, num + 1);
				IO.push('I');
			}
			if (!iO.empty()) {
				iO.pop();
				bruteforce(s, n + 1, num);
				iO.push('i');
			}
		}
		else {
			if (!Io.empty()) {
				Io.pop();
				bruteforce(s, n + 1, num);
				Io.push('I');
			}
			if (!io.empty()) {
				io.pop();
				bruteforce(s, n + 1, num);
				io.push('i');
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;
		bruteforce(s, 0, 0);
		cout << "Case #" << tc << ": " << maxnum << "\n";
		maxnum = 0;
		while (!IO.empty()) {
			IO.pop();
		}
		while (!Io.empty()) {
			Io.pop();
		}
		while (!iO.empty()) {
			iO.pop();
		}
		while (!io.empty()) {
			io.pop();
		}
	}
	return 0;
}