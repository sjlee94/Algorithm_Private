#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
queue<pair<int, int>> bfs_q;
int board[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS() {
	while (!bfs_q.empty()) {
		int y = bfs_q.front().first;
		int x = bfs_q.front().second;
		bfs_q.pop();
		// cout << y << ' ' << x << endl;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny < 0 || nx < 0 || nx >= M || ny >= N)
				continue;

			if (!board[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1; // 해당 지역의 날짜 값 계산을 위해 찾아진 지역에 계속 1일씩 누적
				bfs_q.push(make_pair(ny, nx)); // 해당 위치를 큐에 다시 저장하고 다시 탐색
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer = max(answer, visited[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!board[i][j] && !visited[i][j]) {
				answer = -1;
			}
		}
	}

	cout << answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				bfs_q.push(make_pair(i, j));
				// visited[i][j] = 0; // 초기 토마토가 1인 자리를 0으로 해야 날짜를 바로 구함. (bfs로 발견된 지역이 계속 +1씩 증가함) 위에서 0으로 초기화 되어 있으므로 선언하지 않아도 됨.
			}
		}
	}

	BFS();

	return 0;
}
