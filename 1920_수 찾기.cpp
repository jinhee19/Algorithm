#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;

// 0 1 2 3 4  

bool find_num(int num) {
	int start = 0;
	int end = nums.size() - 1;
	int mid;

	while (start <=  end) {
		mid = (start + end) / 2;
		if (nums[mid] == num)
			return true;
		else if(nums[mid] < num){
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	vector<int> answer;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		nums.push_back(num);
	}

	int M;
	cin >> M;
	vector<int> find;

	for (int i = 0; i < M; i++) {
		cin >> num;
		find.push_back(num);
	}

	// 정렬하기
	sort(nums.begin(), nums.end());

	for (int i = 0; i < find.size(); i++) {
		if (find_num(find[i]))
			answer.push_back(1);
		else
			answer.push_back(0);
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";

	return 0;
}