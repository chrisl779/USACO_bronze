#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	pair<int, int> b;
	pair<int, int> l;
	pair<int, int> r;
	string farm[10];
	for (int i = 0; i < 10; i++) {
		getline(cin, farm[i]);
		for (int j = 0; j < 10; j++) {
			if (farm[i][j] == 'B') {
				 b = { i,j };
			}
			if (farm[i][j] == 'L') {
				 l = { i,j };
			}
			if (farm[i][j] == 'R') {
				r = { i,j };
			}
		}
	}
	int ans = abs(b.first - l.first) + abs(b.second - l.second)-1;

	bool isRBetween =
		// Check horizontal alignment
		((b.first == l.first && l.first == r.first) &&
			((r.second > b.second && r.second < l.second) ||
				(r.second < b.second && r.second > l.second))) ||

		// Check vertical alignment
		((b.second == l.second && l.second == r.second) &&
			((r.first > b.first && r.first < l.first) ||
				(r.first < b.first && r.first > l.first)));

	if (isRBetween) {
		ans += 2;
	}
	cout << ans << '\n';

}