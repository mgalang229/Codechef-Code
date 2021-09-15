#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		long long ans, k;
		cin >> n >> k >> ans;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		string op;
		cin >> op;
		// based on the output observation:
		// XOR operation:
		// there will be at most two (2) results that will be produced 
		// (if 'k' is odd, then the first result, otherwise use the second result)
		// AND / OR operation:
		// since the answer is always the same, then apply it only once or not at all
		if (op == "XOR") {
			vector<long long> res;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < n; j++) {
					ans ^= a[j];
				}
				res.push_back(ans);
			}
			ans = (k % 2 == 1 ? res[0] : res[1]);
		} else if (k > 0) {
			for (int i = 0; i < n; i++) {
				if (op == "AND") {
					ans &= a[i];
				} else {
					ans |= a[i];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
