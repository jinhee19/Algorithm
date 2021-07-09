#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M;

	cin >> N >> M;

	vector<int> vec;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	int start = 0;
	int end = 0;
	int sum = vec[0];
	int answer = 0;

	while(1){
		if (sum == M)
			answer++;
		if (sum < M) {
			end++;
			if (end == vec.size())
				break;
			sum += vec[end];
		}
		else {
			sum -= vec[start];
			start++;
			if (start == vec.size())
				break;
		}
	}

	cout << answer;

	return 0;
}