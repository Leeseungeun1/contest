#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

bool check[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	int isSquare = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (check[arr[i]] == true) isSquare = 2;
		else {
			check[arr[i]] = true;
			int square = (int)sqrt(arr[i]);
			if (square*square == arr[i]) isSquare = 1;
		}
	}
	if (isSquare != -1) {
		cout << isSquare;
	}
	else {
		cout << "what\n";
	}
}