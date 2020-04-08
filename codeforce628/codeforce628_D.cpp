#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int lli;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	lli u, v;
	cin >> u >> v;
	if (u > v) cout << "-1\n";
	else {
		if (u == v) {
			if (u == 0) cout << "0\n";
			else {
				cout << "1\n" << u;
			}
		}
		else if ((u % 2 == 1 && v % 2 == 1)|| (u % 2 == 0 && v % 2 == 0)) {
			lli num = (v - u) / 2;
			vector<lli> vec;
			if (((num + u) ^ num) == u) {
				vec.push_back(num + u);
			}
			else {
				vec.push_back(num); vec.push_back(u);
			}
			vec.push_back(num);
			sort(vec.begin(), vec.end());
			cout << vec.size() << "\n";
			for (int i = 0; i < vec.size(); i++) {
				cout << vec[i] << " ";
			}
		}
		else cout << "-1\n";
	}
	return 0;
}