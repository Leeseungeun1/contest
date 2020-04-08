#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		lli n, now;
		cin >> n >> now;
		vector<pair<lli, pair<lli, lli>>> arr(n);
		for (int i = 0; i < n; i++) {
			lli minute, low, high;
			cin>>minute >> low >> high;
			arr[i] = { minute, {low, high} };
		}
		
		lli nowlow = now;
		lli nowhigh = now;
		lli nowminute = 0;
		bool possible = true;
		for (int i = 0; i < n; i++) {
			lli minute, low, high;
			minute = arr[i].first;
			low = arr[i].second.first;
			high = arr[i].second.second;
			nowlow = nowlow - (minute - nowminute);
			nowhigh = nowhigh + (minute - nowminute);
			if (high < nowlow || nowhigh < low) {
				possible = false;
				break;
			}
			nowlow = max(nowlow, low);
			nowhigh = min(nowhigh, high);
			nowminute = minute;
		}
		if (possible == true) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}