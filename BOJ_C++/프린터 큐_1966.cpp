#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fast_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
	int T, N, M, imp;
	fast_IO;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int cnt = 0;
		queue<pair<int, int>> doc;
		priority_queue<int> imp_cmp;

		cin >> N >> M;

		for (int idx = 0; idx < N; idx++) {
			cin >> imp;
			doc.push(make_pair(idx, imp));
			imp_cmp.push(imp);
		}
		
		while (!doc.empty()) {
			int idx = doc.front().first;
			imp = doc.front().second;
			doc.pop();

			if (imp_cmp.top() == imp) {
				imp_cmp.pop();
				cnt++;
				if (idx == M) {
					break;
				}
			}
			else {
				doc.push(make_pair(idx, imp));
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}
