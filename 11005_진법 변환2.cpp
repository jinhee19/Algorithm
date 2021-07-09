#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int test = 10;

	int N, B;
	vector<int> answer;

	cin >> N >> B;

	while (1) {
		if (N / B == 0) {
			answer.push_back(N%B);
			break;
		}
		else {
			answer.push_back(N%B);
			N = N / B;
		}
	}

	for (int i = answer.size() - 1; i >= 0; i--){
		if (answer[i] < 10) {
			cout << answer[i];
		}
		else {
			printf("%c", answer[i] + 55);
		}
	}
	
	return 0;
}