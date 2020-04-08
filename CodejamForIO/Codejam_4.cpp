#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>

typedef long long int lli;

using namespace std;

pair<lli, lli> arr[1500];
bool check[1500];
lli minimum = LLONG_MAX;
void bruteforce(int level, int N, int num) {
	if (num > N) return;
	if (num == N) {
		if (level == 4) {
			pair<lli, lli> four[4];
			int n = 0;
			for (int i = 0; i < N; i++) {
				if (check[i] == false) continue;
				four[n] = arr[i];
				n++;
			}
			lli y = four[1].first - four[0].first;
			lli x = four[1].second - four[0].second;
			lli c = y * four[0].second - x * four[1].first;
			long double find1 = (long double)(x*four[2].first - c) / y;
			long double find2 = (long double)(x*four[3].first - c) / y;
			if ((find1 - four[2].second)*(find2 - four[3].second) > 0) {
				pair<lli, lli> tmp = four[1];
				four[1] = four[2];
				four[2] = tmp;
			}
			lli dis = (four[1].first - four[0].first)*(four[1].first - four[0].first) + (four[1].second - four[0].second)*(four[1].second - four[0].second);
			long double h1 = (x*four[2].first - y * four[2].second + c)*(x*four[2].first - y * four[2].second + c) / (x*x + y * y);
			long double sq1 = sqrt(dis*h1 / 4);
			long double h2 = (x*four[3].first - y * four[3].second + c)*(x*four[3].first - y * four[3].second + c) / (x*x + y * y);
			long double sq2 = sqrt(dis*h2 / 4);
			minimum = min(minimum, (lli)(sq1 + sq2));
		}
	}
	else {
		check[num] = true;
		bruteforce(level + 1, N, num + 1);
		check[num] = false;
		bruteforce(level, N, num + 1);
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
		minimum = LLONG_MAX;
		for (int i = 0; i < N; i++) {
			check[i] = false;
		}
		for (int i = 0; i < N; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		bruteforce(0, N, 0);
		cout << "Case #1: " << minimum*2 << "\n";
	}
	return 0;
}