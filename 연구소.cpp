#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int row, col; // 가로, 세로
vector<vector<int>> map;
vector<vector<int>> virus_proceed_map;
vector<int> safe_area_list;
queue<pair<int, int>> virus_loc;

// 안전 영역의 크기 구하기
void count_safearea() {
	int count = 0;

	// 바이러스 위치 저장
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 2) {
				virus_loc.push({ i, j });
			}
		}
	}

	virus_proceed_map = map;

	// 바이러스가 퍼지는 상황
	while (!virus_loc.empty()) {
		int ypos = virus_loc.front().first;
		int xpos = virus_loc.front().second;
		virus_loc.pop();

		if (xpos >= 1 && virus_proceed_map[ypos][xpos - 1] == 0) {
			virus_proceed_map[ypos][xpos - 1] = 2;
			virus_loc.push({ ypos, xpos - 1});
		}
		if (xpos <= row - 2 && virus_proceed_map[ypos][xpos + 1] == 0) {
			virus_proceed_map[ypos][xpos + 1] = 2;
			virus_loc.push({ ypos, xpos + 1 });
		}
		if (ypos >= 1 && virus_proceed_map[ypos - 1][xpos] == 0) {
			virus_proceed_map[ypos - 1][xpos] = 2;
			virus_loc.push({ ypos - 1, xpos });
		}
		if (ypos <= col - 2 && virus_proceed_map[ypos + 1][xpos] == 0) {
			virus_proceed_map[ypos + 1][xpos] = 2;
			virus_loc.push({ ypos + 1, xpos });
		}	
	}

	// 바이러스가 퍼진 후 안전지대(0) 개수 세기
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (virus_proceed_map[i][j] == 0)
				count++;
		}
	}
	safe_area_list.push_back(count);

	return;
}


// 벽을 세우는 가능성
void set_block(int count) {
	if (count == 3) {
		// 벽을 3개 세우고 난 상태에서의 안전 영역 크기 구하기
		count_safearea();
		return;
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				set_block(count+1);
				map[i][j] = 0;
			}
		}
	}
	return;
}

int main() {
	int num = 0;
	vector<int> insert;

	// 지도의 세로 크기, 가로 크기 입력
	cin >> col >> row;

	// 지도의 모양 입력
	for (int i = 0; i < col; i++) {
		map.push_back(insert);
		for (int j = 0; j < row; j++) {
			cin >> num;
			map[i].push_back(num);
		}
	}

	
	set_block(0);

	sort(safe_area_list.begin(), safe_area_list.end());

	cout << safe_area_list[safe_area_list.size()-1] << endl;
	
	return 0;
}
