#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;


// 방 배정하기
  // dp를 이용한 방식

int main() {
	int num = 0;
	int room[3];
	int dp[301] = { 0 };

	for (int i = 0; i < 3; i++)
		cin >> room[i];
	cin >> num;

	dp[num] = 1;

	for (int i = num; i > 0; i--) {
		if (!dp[i]) continue;
		for (int j = 0; j < 3; j++) {
			if (i - room[j] >= 0) dp[i - room[j]] = 1;
		}
	}

	// 방 배정 후 남은 인원수가 0명일 때 => 즉 다 배정했을 때
	if (dp[0] == 1)
		cout << 1;
	else
		cout << 0;

	return 0;
}

  // for문을 이용한 방식
/*
int main() {
	int num = 0;
	int sum = 0;
	int a, b, c = 0;
	bool flag = 0;

	cin >> a >> b >> c >> num;

	for (int i = 0; i <= num / c; i++) {
		sum = c * i;
		for (int j = 0; j <= num / b; j++) {
			sum = sum + b * j;
			for (int k = 0; k <= num / a; k++) {
				sum = sum + a * k;
				if (sum == num) {
					cout << 1;
					return 0;
				}
			}
		}
	}

	cout << 0;

	return 0;
}
*/
