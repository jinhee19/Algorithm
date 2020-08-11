#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int y_row = 0;
	int t_row = 0;
	int y_col = 0;
	int t_col = 0;

	for (int i = 1; i <= yellow; i++) {
		if (yellow % i == 0) {
			y_row = i;
			y_col = yellow / i;
			if (((y_row + 2)*(y_col + 2) - yellow == brown) && y_row <= y_col) {
				t_row = y_row + 2;
				t_col = y_col + 2;
				break;
			}
		}
	}
    answer.push_back(t_col);
    answer.push_back(t_row);
    return answer;
}
