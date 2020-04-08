#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
typedef long long int lli;
using namespace std;

const int alphabet = 26;
inline int ctoi(char c) { return c - 'A'; }
struct Trie {
	int number;
	struct Trie* child[alphabet];
	Trie() {
		number = 0;
		memset(child, 0, sizeof(child));
	}
	~Trie() {
		for (int i = 0; i < alphabet; i++) {
			delete child[i];
		}
	}
	int insert(const char* key, int size, int K, int n) {
		if (*key == 0) {
			if (number%K == 0) return size;
			else return n;
		}
		else {
			int nextn = n;
			if (number%K == 0) {
				nextn = max(n, size);
			}
			int num = ctoi(*key);
			if (child[num] == NULL) {
				child[num] = new Trie();
			}
			child[num]->number += 1;
			return child[num]->insert(key + 1,size+1, K, nextn);
		}
	}
};

bool cmp(string a, string b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;
		vector<string> str;
		Trie trie = Trie();
		lli ans = 0;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			str.push_back(s);
		}
		sort(str.begin(), str.end(), cmp);
		for (int i = 0; i < str.size(); i=i+K) {
			int minimum = min(str[i].size(), str[i + K - 1].size());
			for (int n = 0; n < minimum; n++) {
				if (str[i][n] == str[i + K - 1][n]) ans++;
				else break;
			}
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}