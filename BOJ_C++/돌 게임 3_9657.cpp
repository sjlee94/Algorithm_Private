#include <iostream>
#include <string>

using namespace std;

int N = 0;
int minus_stone[3] = { 1, 3 ,4 };
int dp[1000];

string stone_game(int stone_num) {
  
  // 돌을 1 3 4개 를 가져갈 수 있다. 그 때 남은 돌이 없으면 SK가 이기므로 1
  // ex) 돌이 5개인 경우 SK가 먼저 1개, 3개, 4개를 가져갈 경우 모두 CY가 이기는 경우가 된다.
  // 이를 DP를 활용하여 연산을 지속한다.
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= stone_num; i++) {
		if (dp[i - minus_stone[0]] == 1 && dp[i - minus_stone[1]] == 1 && dp[i - minus_stone[2]] == 1) {
			dp[i] = 0;
		}
		else {
			dp[i] = 1;
		}
	}

	if (dp[stone_num] == 1) {
		return "SK";
	}
	else {
		return "CY";
	}
}

int main() {
	cin >> N;
  
	string answer = "";

	answer = stone_game(N);

	cout << answer;

	return 0;
}
